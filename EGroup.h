#ifndef GROUP_INCLUDED_HPP
#define GROUP_INCLUDED_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>

class EGroup : public sf::Drawable {

public:
	EGroup();
	virtual ~EGroup() = default;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	const sf::Drawable& operator[](std::size_t index);
	std::size_t push_back(const sf::Drawable& drawable);
	const sf::Drawable& pop_back();
	void removeAt(const sf::Drawable* draw);
	int getSize();
	const sf::Drawable& getDrawable(int index);
	

private:
	std::vector<std::reference_wrapper<const sf::Drawable>> m_drawables;
};

#endif
