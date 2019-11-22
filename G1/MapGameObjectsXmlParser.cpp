#include "MapGameObjectsXmlParser.h"

namespace G1 {

	Transform MapGameObjectsXmlParser::loadTransform(boost::property_tree::ptree::value_type & val)
	{
		using namespace boost::property_tree;

		Transform transform;
		BOOST_FOREACH(ptree::value_type &v, val.second.get_child("")) {
			std::string label = v.first;
			if (label == "position") {
				transform.position.x = v.second.get<float>("x", 0.0f);
				transform.position.y = v.second.get<float>("y", 0.0f);
			}
			else if (label == "scale") {
				transform.scale.x = v.second.get<float>("x", 1.0f);
				transform.scale.y = v.second.get<float>("y", 1.0f);
			}
			else if (label == "rotationX") {
				transform.rotationX = val.second.get<float>(label, 0.0f);
			}
		}
		return transform;
	}

	prefabArgs MapGameObjectsXmlParser::loadArgs(boost::property_tree::ptree::value_type& val)
	{
		using namespace boost::property_tree;

		prefabArgs args;
		BOOST_FOREACH(ptree::value_type &obj, val.second.get_child("")) {
			if (obj.first == "args") {
				prefabArgs args;
				BOOST_FOREACH(ptree::value_type &v, obj.second.get_child("")) {
					std::string label = v.first;
					std::string type = v.second.get("<xmlattr>.type", "");

					prefabArg arg;
					if (type == "int") {
						arg = obj.second.get<int>(label);
					}
					else if (type == "float") {
						arg = obj.second.get<float>(label);
					}
					else if (type == "bool") {
						arg = obj.second.get<bool>(label);
					}
					else if (type == "string") {
						arg = obj.second.get<std::string>(label);
					}
					args[label] = arg;
				}
				return args;
			}
		}
		return args;
	}

	std::vector<Component*> MapGameObjectsXmlParser::loadComponents(boost::property_tree::ptree::value_type & val)
	{
		return std::vector<Component*>();
	}

}
