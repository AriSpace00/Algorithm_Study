template <typename T>
class CustomAllocator : public std::allocator<T>
{
public:
    using value_type = T;

    // �⺻ ������
    CustomAllocator() noexcept = default;

    // ���� ������
    template <typename U>
    constexpr CustomAllocator(const CustomAllocator<U>&) noexcept {}

    // �Ҵ�
    [[nodiscard]] T* allocate(std::size_t n) {
        std::cout << "CustomAllocator: allocate " << n << " elements\n";
        return std::allocator<T>::allocate(n);
    }

    // ����
    void deallocate(T* p, std::size_t n) {
        std::cout << "CustomAllocator: deallocate " << n << " elements\n";
        std::allocator<T>::deallocate(p, n);
    }
};
