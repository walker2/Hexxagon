#ifndef HEXXAGON_RESOURCEMANAGER_H
#define HEXXAGON_RESOURCEMANAGER_H


#include <SFML/Graphics/Font.hpp>

class ResourceManager
{
public:
    ResourceManager() {};
    ~ResourceManager() {};
    void addFont(const std::string &path, sf::Font font);
    void addImage(const std::string &path, sf::Texture image);

    sf::Font& getFont(const std::string &path);
    sf::Texture& getImage(const std::string &path);

private:
    std::map<std::string, sf::Font> m_fonts;
    std::map<std::string, sf::Texture> m_images;
};


#endif