out vec4 fragColor;

void main() {
    uint r = (pickingID & 0x000000FF) >>  0;
    uint g = (pickingID & 0x0000FF00) >>  8;
    uint b = (pickingID & 0x00FF0000) >> 16;
    fragColor = vec4(r / 255.0f, g / 255.0f, b / 255.0f, 1.0f);
}
