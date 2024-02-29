#pragma once

const char *FRAGMENT_SHADER = R"(

#version 410 core

in vec2 texCoord;
uniform sampler2D tex;

out vec4 fColor;

void main() {
	fColor = texture(tex, texCoord);
}


)";

const char *const F_SHADER[] = {FRAGMENT_SHADER};