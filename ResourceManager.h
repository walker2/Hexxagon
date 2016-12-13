#ifndef HEXXAGON_RESOURCEMANAGER_H
#define HEXXAGON_RESOURCEMANAGER_H


#include <SFML/Graphics/Font.hpp>
/**
 * Class for loading and caching textures and fonts
 */
class ResourceManager
{
public:
    ResourceManager() {};
    ~ResourceManager() {};

    /**
     * Function for adding fonts to map container
     * @param path Path to font in our directory
     * @param font Font that we should add
     */
    void addFont(const std::string &path, sf::Font font);

    /**
     * Function for adding images to map container
     * @param path Path to texture in our directory
     * @param font Texture that we should add
     */
    void addImage(const std::string &path, sf::Texture image);

    /**
     * Function that finds font in container and adds it to container if there's none
     * @param path Path to font in our directory
     * @return Reference to sf::Font
     */
    sf::Font& getFont(const std::string &path);
    /**
     * Function that finds texture in container and adds it to container if there's none
     * @param path Path to texture in our directory
     * @return Reference to sf::Texture
     */
    sf::Texture& getImage(const std::string &path);

private:
    std::map<std::string, sf::Font> m_fonts; ///< Container with all the fonts
    std::map<std::string, sf::Texture> m_images; ///< Container with all the tetures
};


#endif