#include "parser.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <unordered_map>

#include "scenedata.h"

static std::unordered_map<std::string, Material*> material_map;

bool startsNumericAttribute(const std::string& token) {
	std::regex pattern{ "^[_a-zA-Z][_a-zA-Z0-9]*:.*" };
	return std::regex_match(token, pattern);
}

bool startsVectorAttribute(const std::string& token) {
	std::regex pattern{ "^->[_a-zA-Z][_a-zA-Z0-9]*:.*" };
	return std::regex_match(token, pattern);
}

bool startsStringAttribute(const std::string& token) {
	std::regex pattern{ "^\\$[_a-zA-Z][_a-zA-Z0-9]*:.*" };
	return std::regex_match(token, pattern);
}

bool startsAttribute(const std::string& token) {
	return startsNumericAttribute(token) || startsStringAttribute(token) ||
		startsVectorAttribute(token);
}

std::string getAttributeName(const std::string& token) {
	std::regex pattern{ R"(^((?:\$|->)?[_a-zA-Z][_a-zA-Z0-9]*))" };
	std::smatch match;
	if (!std::regex_search(token, match, pattern)) {
		throw "Invalid attribute: " + token;
	}
	if (match.size() < 2) {
		throw "Invalid attribute: " + token;
	}
	return match[1];
}

float getNumericAttributeValue(const std::string& token) {
	std::regex pattern{ R"(:(\d+(?:\.\d+)?))" };
	std::smatch match;
	if (!std::regex_search(token, match, pattern)) {
		throw "Invalid numeric attribute: " + token;
	}
	if (match.size() < 2) {
		throw "Invalid numeric attribute: " + token;
	}
	std::string m = match[1];
	return std::stof(m);
}

std::string getStringAttributeValue(const std::string& token) {
	std::regex pattern{ ":\"(.*?)\"$" };
	std::smatch match;
	if (!std::regex_search(token, match, pattern)) {
		throw "Invalid string attribute: " + token;
	}
	if (match.size() < 2) {
		throw "Invalid string attribute: " + token;
	}
	std::string m = match[1];
	return m;
}

Vect getVectorAttributeValue(const std::string& token) {
	std::regex pattern(R"(:\((\d+(?:\.\d+)?),(\d+(?:\.\d+)?),(\d+(?:\.\d+)?)\))");
	std::smatch match;
	if (!std::regex_search(token, match, pattern)) {
		throw "Invalid vector attribute: " + token;
	}
	if (match.size() < 4) {
		throw "Invalid vector attribute: " + token;
	}
	std::string p0 = match[1];
	std::string p1 = match[2];
	std::string p2 = match[3];
	return Vect(std::stof(p0), std::stof(p1), std::stof(p2));
}

void parseLight(std::vector<std::string> attributes, RenderingInfo* rinfo) {
	Light* light = new Light();
	for (auto attribute : attributes) {
		if (startsVectorAttribute(attribute)) {
			std::string name = getAttributeName(attribute);
			if (name == "->pos") {
				light->position = getVectorAttributeValue(attribute);
			} else {
				throw "Unrecognized vector attribute: " + name;
			}
		} else if (startsNumericAttribute(attribute)) {
			std::string name = getAttributeName(attribute);
			if (name == "i") {
				light->intensity = getNumericAttributeValue(attribute);
			} else {
				throw "Unrecognized numeric attribute: " + name;
			}
		} else {
			throw "Unrecognized attribute: " + attribute;
		}
	}
	rinfo->point_lights.push_back(light);
}

void parseDirection(std::vector<std::string> attributes, RenderingInfo* rinfo) {
	DirectionalLight* dlight = new DirectionalLight();
	for (auto attribute : attributes) {
		if (startsVectorAttribute(attribute)) {
			std::string name = getAttributeName(attribute);
			if (name == "->d") {
				dlight->direction = getVectorAttributeValue(attribute);
			} else {
				throw "Unrecognized vector attribute: " + name;
			}
		} else if (startsNumericAttribute(attribute)) {
			std::string name = getAttributeName(attribute);
			if (name == "h") {
				dlight->h_intensity = getNumericAttributeValue(attribute);
			} else {
				throw "Unrecognized numeric attribute: " + name;
			}
		} else {
			throw "Unrecognized attribute: " + attribute;
		}
	}
	rinfo->dir_light = dlight;
}

void parseGlobal(std::vector<std::string> attributes, RenderingInfo* rinfo) {
	for (auto attribute : attributes) {
		if (startsNumericAttribute(attribute)) {
			std::string name = getAttributeName(attribute);
			if (name == "ambient") {
				rinfo->ambient = getNumericAttributeValue(attribute);
			} else if (name == "focal_length") {
				rinfo->focal_length = getNumericAttributeValue(attribute);
			} else {
				throw "Unrecognized numeric attribute: " + name;
			}
		} else {
			throw "Unrecognized attribute: " + attribute;
		}
	}
}

void parseSphere(std::vector<std::string> attributes, RenderingInfo* rinfo) {
	Sphere* sphere = new Sphere();
	for (auto attribute : attributes) {
		if (startsNumericAttribute(attribute)) {
			std::string name = getAttributeName(attribute);
			if (name == "radius") {
				sphere->radius = getNumericAttributeValue(attribute);
			} else {
				throw "Unrecognized numeric attribute: " + name;
			}
		} else if (startsVectorAttribute(attribute)) {
			std::string name = getAttributeName(attribute);
			if (name == "->center") {
				sphere->center = getVectorAttributeValue(attribute);
			} else {
				throw "Unrecognized vector attribute: " + name;
			}
		} else if (startsStringAttribute(attribute)) {
			std::string name = getAttributeName(attribute);
			if (name == "$mat") {
				sphere->materialName = getStringAttributeValue(attribute);
			} else {
				throw "Unrecognized string attribute: " + name;
			}
		} else {
			throw "Unrecognized attribute: " + attribute;
		}
	}
	rinfo->spheres.push_back(sphere);
}

void parseTriangle(std::vector<std::string> attributes, RenderingInfo* rinfo) {
	Triangle* triangle = new Triangle();
	for (auto attribute : attributes) {
		if (startsVectorAttribute(attribute)) {
			std::string name = getAttributeName(attribute);
			if (name == "->p0") {
				triangle->p0 = getVectorAttributeValue(attribute);
			} else if (name == "->p1") {
				triangle->p1 = getVectorAttributeValue(attribute);
			} else if (name == "->p2") {
				triangle->p2 = getVectorAttributeValue(attribute);
			} else {
				throw "Unrecognized vector attribute: " + name;
			}
		} else if (startsStringAttribute(attribute)) {
			std::string name = getAttributeName(attribute);
			if (name == "$mat") {
				triangle->materialName = getStringAttributeValue(attribute);
			} else {
				throw "Unrecognized string attribute: " + name;
			}
		} else {
			throw "Unrecognized attribute: " + attribute;
		}
	}
	rinfo->triangles.push_back(triangle);
}

void parseMaterial(std::vector<std::string> attributes, RenderingInfo* rinfo) {
	Material* mat = new Material();
	for (auto attribute : attributes) {
		if (startsNumericAttribute(attribute)) {
			std::string name = getAttributeName(attribute);
			if (name == "gloss") {
				mat->glossiness = getNumericAttributeValue(attribute);
			} else if (name == "p") {
				mat->p = getNumericAttributeValue(attribute);
			} else {
				throw "Unrecognized numeric attribute: " + name;
			}
		} else if (startsVectorAttribute(attribute)) {
			std::string name = getAttributeName(attribute);
			if (name == "->col") {
				Vect v = getVectorAttributeValue(attribute);
				Color c = Color(v.x, v.y, v.z);
				mat->color = c;
			} else {
				throw "Unrecognized vector attribute: " + name;
			}
		} else if (startsStringAttribute(attribute)) {
			std::string name = getAttributeName(attribute);
			if (name == "$name") {
				std::string value = getStringAttributeValue(attribute);
				mat->name = value;
				material_map[value] = mat;
			} else {
				throw "Unrecognized string attribute: " + name;
			}
		} else {
			throw "Unrecognized attribute: " + attribute;
		}
	}
	rinfo->materials.push_back(mat);
}

void parseLine(std::string line, RenderingInfo* rinfo) {
	// first parse file
	std::stringstream ss(line);
	std::string token;
	std::vector<std::string> raw_tokens;
	std::vector<std::string> attributes;

	while (ss >> token) {
		raw_tokens.push_back(std::string(token));
	}

	std::string object_type;
	std::string current_attribute = "NOT_STARTED";

	// we want to condense some tokens.
	for (int i = 0; i < raw_tokens.size(); i++) {
		auto rtoken = raw_tokens[i];
		if (i == 0) {
			object_type = rtoken;
		} else {
			if (startsAttribute(rtoken)) {
				if (current_attribute != "NOT_STARTED") {
					attributes.push_back(current_attribute);
				}
				current_attribute = rtoken;
			} else {
				current_attribute += rtoken;
			}
		}
	}
	if (current_attribute != "NOT_STARTED") {
		attributes.push_back(current_attribute);
	}
	if (object_type == "material") {
		parseMaterial(attributes, rinfo);
	} else if (object_type == "light") {
		parseLight(attributes, rinfo);
	} else if (object_type == "direction") {
		parseDirection(attributes, rinfo);
	} else if (object_type == "sphere") {
		parseSphere(attributes, rinfo);
	} else if (object_type == "triangle") {
		parseTriangle(attributes, rinfo);
	} else if (object_type == "global") {
		parseGlobal(attributes, rinfo);
	} else {
		throw std::string("Unrecognized object type: " + object_type);
	}
}

RenderingInfo* Parser::parseFile(std::string filename) {
	RenderingInfo* rinfo = new RenderingInfo();
	std::ifstream file(filename);
	if (file.is_open()) {
		std::string line;
		while (getline(file, line)) {
			if (line.empty()) {
				continue;
			} else if (line[0] == '#') {
				continue;
			} else {
				parseLine(line, rinfo);
			}
		}
	} else {
		std::cout << "File " << filename << " failed to open" << std::endl;
		return nullptr;
	}
	for (auto sphere : rinfo->spheres) {
		if (material_map.find(sphere->materialName) == material_map.end()) {
			throw "Material " + sphere->materialName + " not found";
		}
		sphere->material = material_map[sphere->materialName];
	}
	for (auto triangle : rinfo->triangles) {
		if (material_map.find(triangle->materialName) == material_map.end()) {
			throw "Material " + triangle->materialName + " not found";
		}
		triangle->material = material_map[triangle->materialName];
	}
	return rinfo;
}