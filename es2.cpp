#include <iostream>
#include <tuple>
#include <array>


template <size_t N, size_t M>
using image_t = std::array<std::array<int, M>, N>;

using XY_t = std::tuple<int, int>;

XY_t operator+ (const XY_t& a, const XY_t& b)
{
    return std::make_tuple(std::get<0>(a) + std::get<0>(b),
                        std::get<1>(a) + std::get<1>(b));
}

std::array<XY_t, 4> moves = {{ {1,0}, {-1, 0}, {0, 1}, {0, -1} }};

template <size_t N, size_t M>
void flip_helper (image_t<N,M>& image, const XY_t& pos, int color) 
{
    auto x = std::get<0>(pos);
    auto y = std::get<1>(pos);
    image[x][y] = color;
    for (const auto move: moves) {
        auto next_pos = pos+move;
        auto next_x = std::get<0>(next_pos);
        auto next_y = std::get<1>(next_pos);
        if (next_x >= 0 && next_x < image.size() &&
            next_y >= 0 && next_y < image[0].size() &&
            image[next_x][next_y] != color) {
            flip_helper(image, next_pos, color);
        }
    }
}

template <size_t N, size_t M>
void flip (image_t<N,M> &image, const XY_t& start)
{
    flip_helper(image, start, !image[std::get<0>(start)][std::get<1>(start)]);
}


int main (void)
{
    image_t<10, 7> image = {{
        {{0, 0, 0, 0, 0, 0, 0}},
        {{0, 1, 1, 1, 1, 1, 0}},
        {{0, 1, 0, 0, 0, 1, 0}},
        {{0, 1, 0, 0, 0, 1, 0}},
        {{0, 1, 0, 0, 0, 1, 0}},
        {{0, 1, 0, 0, 0, 1, 0}},
        {{0, 1, 0, 0, 0, 1, 0}},
        {{0, 1, 0, 0, 0, 1, 0}},
        {{0, 1, 1, 1, 1, 1, 0}},
        {{0, 0, 0, 0, 0, 0, 0}},
    }};
    flip(image, std::make_tuple(3,4));

    
    for (const auto& r: image) {
        for (const auto& c: r) {
            std::cout << c << ",";
        }
        std::cout << std::endl;
    }

    return 0;
}
