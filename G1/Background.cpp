#include "Background.h"

Background::Background() {
	sprite = new Sprite(Assets::getInstance().textures().get("./assets/environment/layers/back.png"), 
		Vector2(384, 240));
	sprite->setImageSize(Vector2(1000, 240));
	//Vector2(384, 240));
}

Background::Background(const G1::prefabArgs & args)
{
	std::string imagePath = std::get<std::string>(args.at("imagePath"));
	int w = std::get<int>(args.at("imgWidth"));
	int h = std::get<int>(args.at("imgHeight"));

	sprite = new Sprite(Assets::getInstance().textures().get(imagePath),
		Vector2(w, h));

	w = std::get<int>(args.at("width"));
	h = std::get<int>(args.at("height"));
	sprite->setImageSize(Vector2(w, h));
	
	int x = std::get<int>(args.at("offX"));
	int y = std::get<int>(args.at("offY"));
	offset = Vector2(x, y);

	lerpTime = std::get<float>(args.at("lerp"));
}

Background::Background(const sf::Texture& texture, const Vector2& size)
{
	sprite = new Sprite(texture, size);
}

void Background::startPlay() {
	addComponent(sprite);
}

void Background::beginPlay() {
	startPos = Camera::getActiveCameras().at(0)->getWorldPosition();
	startPos += offset;
}

void Background::eventTick()
{
	Vector2 pos = Camera::getActiveCameras().at(0)->getWorldPosition();
	setPosition(Vector2::lerp(pos, startPos, lerpTime));
}

// TODO: addComponent should handle deletion of components OR use smart pointers
