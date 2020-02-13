#include "MapTile.h"

MapTile::MapTile(const G1::prefabArgs & args)
{
	x = std::get<int>(args.at("x"));
	y = std::get<int>(args.at("y"));
	xSpan = std::get<int>(args.at("xSpan"));
	ySpan = std::get<int>(args.at("ySpan"));

	collision = std::get<bool>(args.at("collision"));
	setLayer(Layer(1 << std::get<int>(args.at("layer"))));
}
