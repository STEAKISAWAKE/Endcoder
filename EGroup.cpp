#include "EGroup.h"

EGroup::EGroup()
	: m_drawables{} {
	m_drawables.empty();
}

void EGroup::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (const auto& drawable : m_drawables) {
		target.draw(drawable, states);
	}

	//for (int t = 0; t < m_drawables.size(); t++) {
	//	target.draw(m_drawables[t], states);
	//}
}

const sf::Drawable& EGroup::operator[](std::size_t index) {
	return m_drawables[index];
}

std::size_t EGroup::push_back(const sf::Drawable& drawable) {
	m_drawables.push_back(drawable);
	return m_drawables.size() - 1;
}

const sf::Drawable& EGroup::pop_back() {
	const auto& drawable = m_drawables.back();
	m_drawables.pop_back();
	return drawable;
}

void EGroup::removeAt(const sf::Drawable* draw)
{

	for (int t = 0; t < m_drawables.size(); t++) {
		if (&m_drawables[t].get() == draw) {
			m_drawables.erase(m_drawables.begin() + t);
		}
	}

	m_drawables.shrink_to_fit();

}

int EGroup::getSize()
{
	return m_drawables.size();
}

const sf::Drawable& EGroup::getDrawable(int index)
{
	return m_drawables[index];
}
