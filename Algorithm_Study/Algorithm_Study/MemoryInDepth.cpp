#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <intsafe.h>
#include <iostream>
using namespace std;

class CPrivateHeapCat
{
public:
    CPrivateHeapCat()
    {
        cout << "CPrivateHeapCat 생성자" << endl;
    }
    ~CPrivateHeapCat()
    {
        cout << "CPrivateHeapCat 소멸자" << endl;
    }

    void* operator new(size_t size)
    {
        if (nullptr == s_hHeap)
        {
            s_hHeap = ::HeapCreate(NULL, 0, 0);

            if (s_hHeap == nullptr) return nullptr;
        }

        void* ptr = ::HeapAlloc(s_hHeap, 0, size);
        if (nullptr != ptr)
        {
            s_dwNumAllocInHeap++;
        }
        return (ptr);
    }
    void operator delete(void* p)
    {
        if (::HeapFree(s_hHeap, 0, p))
        {
            s_dwNumAllocInHeap--;
        }

        if (s_dwNumAllocInHeap == 0)
        {
            if (::HeapDestroy(s_hHeap))
                s_hHeap = nullptr;
        }
    }

private:
    static HANDLE s_hHeap;
    static DWORD s_dwNumAllocInHeap;
};

HANDLE CPrivateHeapCat::s_hHeap = nullptr;
DWORD CPrivateHeapCat::s_dwNumAllocInHeap = 0;


class CCat
{
public:
    CCat()
    {
        cout << "CCat 생성자" << endl;
    }
    ~CCat()
    {
        cout << "CCat 소멸자" << endl;
    }

};

void TestCat()
{
    CPrivateHeapCat* pPCat = new CPrivateHeapCat;
    CCat* pCat = new CCat;

    // 주소를 확인해 봅시다.
    cout << pCat << endl;
    cout << pPCat << endl;

    //delete pCat;
    //delete pPCat;
}


int __cdecl _tmain()
{
    DWORD NumberOfHeaps;
    DWORD HeapsIndex;
    DWORD HeapsLength;
    HANDLE hDefaultProcessHeap;
    HRESULT Result;
    PHANDLE aHeaps;
    SIZE_T BytesToAllocate;


    TestCat();

    //
    // Retrieve the number of active heaps for the current process
    // so we can calculate the buffer size needed for the heap handles.
    //
    NumberOfHeaps = GetProcessHeaps(0, NULL);
    if (NumberOfHeaps == 0) {
        _tprintf(TEXT("Failed to retrieve the number of heaps with LastError %d.\n"),
            GetLastError());
        return 1;
    }

    //
    // Calculate the buffer size.
    //
    Result = SIZETMult(NumberOfHeaps, sizeof(*aHeaps), &BytesToAllocate);
    if (Result != S_OK) {
        _tprintf(TEXT("SIZETMult failed with HR %d.\n"), Result);
        return 1;
    }

    //
    // Get a handle to the default process heap.
    //
    hDefaultProcessHeap = GetProcessHeap();
    if (hDefaultProcessHeap == NULL) {
        _tprintf(TEXT("Failed to retrieve the default process heap with LastError %d.\n"),
            GetLastError());
        return 1;
    }

    //
    // Allocate the buffer from the default process heap.
    //
    aHeaps = (PHANDLE)HeapAlloc(hDefaultProcessHeap, 0, BytesToAllocate);
    if (aHeaps == NULL) {
        _tprintf(TEXT("HeapAlloc failed to allocate %d bytes.\n"),
            BytesToAllocate);
        return 1;
    }

    // 
    // Save the original number of heaps because we are going to compare it
    // to the return value of the next GetProcessHeaps call.
    //
    HeapsLength = NumberOfHeaps;

    //
    // Retrieve handles to the process heaps and print them to stdout. 
    // Note that heap functions should be called only on the default heap of the process
    // or on private heaps that your component creates by calling HeapCreate.
    //
    NumberOfHeaps = GetProcessHeaps(HeapsLength, aHeaps);
    if (NumberOfHeaps == 0) {
        _tprintf(TEXT("Failed to retrieve heaps with LastError %d.\n"),
            GetLastError());
        return 1;
    }
    else if (NumberOfHeaps > HeapsLength) {

        //
        // Compare the latest number of heaps with the original number of heaps.
        // If the latest number is larger than the original number, another
        // component has created a new heap and the buffer is too small.
        //
        _tprintf(TEXT("Another component created a heap between calls. ") \
            TEXT("Please try again.\n"));
        return 1;
    }

    _tprintf(TEXT("Process has %d heaps.\n"), HeapsLength);
    for (HeapsIndex = 0; HeapsIndex < HeapsLength; ++HeapsIndex) {
        _tprintf(TEXT("Heap %d at address: %#p.\n"),
            HeapsIndex,
            aHeaps[HeapsIndex]);
    }

    //
    // Release memory allocated from default process heap.
    //
    if (HeapFree(hDefaultProcessHeap, 0, aHeaps) == FALSE) {
        _tprintf(TEXT("Failed to free allocation from default process heap.\n"));
    }

    return 0;
}