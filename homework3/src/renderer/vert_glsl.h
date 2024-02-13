#pragma once

const char *VERTEX_SHADER = R"(

#version 410 core

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec2 vTexCoord;

out vec2 texCoord;

void main() {
	gl_Position = vPosition;
    texCoord = vTexCoord;
}


)";

const char *const V_SHADER[] = {VERTEX_SHADER};