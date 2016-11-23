#include "ResourceManager.h"

void ResourceManager::addFont(const std::string &path, sf::Font font)
{
    m_fonts.emplace(path, font);
}

void ResourceManager::addImage(const std::string &path, sf::Texture image)
{
    m_images.emplace(path, image);
}

sf::Font& ResourceManager::getFont(const std::string &path)
{
    auto font = m_fonts.find(path);
    if (font != m_fonts.end())
    {
        return font->second;
    }
    else
    {
        sf::Font font;
        font.loadFromFile(path);
        addFont(path, font);
        return m_fonts[path];
    }

}

sf::Texture& ResourceManager::getImage(const std::string &path)
{
    auto image = m_images.find(path);
    if (image != m_images.end())
    {
        return image->second;
    }
    else
    {
        sf::Texture image;
        image.loadFromFile(path);
        addImage(path, image);
        return m_images[path];
    }
}
