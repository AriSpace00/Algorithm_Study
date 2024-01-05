template <typename T>
class CustomAllocator : public std::allocator<T>
{
public:
    using value_type = T;

    // 기본 생성자
    CustomAllocator() noexcept = default;

    // 복사 생성자
    template <typename U>
    constexpr CustomAllocator(const CustomAllocator<U>&) noexcept {}

    // 할당
    [[nodiscard]] T* allocate(std::size_t n) {
        std::cout << "CustomAllocator: allocate " << n << " elements\n";
        return std::allocator<T>::allocate(n);
    }

    // 해제
    void deallocate(T* p, std::size_t n) {
        std::cout << "CustomAllocator: deallocate " << n << " elements\n";
        std::allocator<T>::deallocate(p, n);
    }
};
