
#version 330 core
out vec4 FragColor;
  
uniform float ourColor; // we set this variable in the OpenGL code.

void main()
{
    FragColor = vec4(0.0, ourColor, 0.0, 1.0);
}   