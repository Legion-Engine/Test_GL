#include <math/color.hpp>

#include <sstream>

#define bswap_32(x) ((((x) & 0xFF000000) >> 24) | \
                     (((x) & 0x00FF0000) >> 8)  | \
                     (((x) & 0x0000FF00) << 8)  | \
                     (((x) & 0x000000FF) << 24) )

color color::Red = color(255u, 0u, 0u, 255u);
color color::Green = color(0u, 255u, 0u, 255u);
color color::Blue = color(0u, 0u, 255u, 255u);
color color::White = color(255u, 255u, 255u, 255u);
color color::Black = color(0u, 0u, 0u, 255u);
color color::Yellow = color(255u, 255u, 0u, 255u);
color color::Orange = color(255u, 165u, 0u, 255u);
color color::Purple = color(160u, 32u, 240u, 255u);
color color::Cyan = color("00ffff");
color color::Magenta = color("ff00ff");
color color::Brown = color("7B4A12");
color color::Grey = color(128u, 128u, 128u, 255u);
color color::CornFlower = color(154u, 206u, 235u, 255u);
color color::WhiteTransparent = color::White.Transparent();
color color::BlackTransparent = color::Black.Transparent();

color::color(std::string hexstring)
{
    if (hexstring.length() == 6)
        hexstring.append("ff");

    std::stringstream ss;
    unsigned int temp;
    ss << std::hex << hexstring;
    ss >> temp;
    integervalue = bswap_32(temp);
}

color color::operator*(const color& c) const
{
    color t(static_cast<byte>((static_cast<uint>(r) * static_cast<uint>(c.r)) / 255u),
            static_cast<byte>((static_cast<uint>(g) * static_cast<uint>(c.g)) / 255u),
            static_cast<byte>((static_cast<uint>(b) * static_cast<uint>(c.b)) / 255u),
            static_cast<byte>((static_cast<uint>(a) * static_cast<uint>(c.a)) / 255u));

    return t;
}

color color::Transparent(float opacity) const
{
    return color(this->r, this->g, this->b, static_cast<byte>(opacity * 255.f));
}

