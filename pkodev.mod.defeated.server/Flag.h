#pragma once

namespace pkodev {

    template<class T>
    class Automatic;

    template<class T>
    struct Flag final {
        bool state{ false };
        T data{T()};
        Automatic<T> Spawn() { return Automatic(*this); }
    };

    template <class T>
    class Automatic final {
    public:
        Automatic(Flag<T>& flag) :
            m_flag(flag) {
            m_flag.state = true;
        }
        ~Automatic() { m_flag.state = false; }
    private:
        Flag<T>& m_flag;
    };

}
