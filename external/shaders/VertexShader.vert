#version 330 core
layout(location = 0) in vec3 aPos; // the position variable has attribute index 0  
layout(location = 1) in vec3 aCol; // the color variable has attribute index 1  


out vec4 ourColor; // specify a color output to the fragment shader

void main()
{
    gl_Position =   vec4(aPos, 1.0); // Mandotary Default Output variable 

    ourColor = vec4(aCol,1.0); // set the output variable to a dark-red color
}