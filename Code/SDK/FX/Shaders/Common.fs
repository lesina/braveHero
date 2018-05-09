#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

// texture samplers
uniform sampler2D textureHero;
uniform sampler2D textureBullet;

void main()
{
	FragColor = texture(textureHero, TexCoord);
}