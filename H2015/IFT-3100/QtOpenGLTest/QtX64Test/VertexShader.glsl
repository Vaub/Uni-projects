#version 430

in layout(location=0) vec3 vertexPosition;
in layout(location=1) vec4 vertexColor;

out vec4 theColor;

void main()
{
	gl_Position = vec4(vertexPosition, 1.0);
	theColor = vertexColor;
}