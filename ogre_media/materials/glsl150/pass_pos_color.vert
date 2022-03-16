#version 150 compatibility

// this merely passes over position and color as needed by box.geom

out VertexData {
    vec4 color;
} vdata;

void main() {
    gl_Position = gl_Vertex;
    vdata.color = gl_Color;
}
