#version 120

// rasterizes a smooth square with ax,ay in [-0.5..0.5]

uniform vec4 highlight;
uniform float alpha;

void main()
{
  const float inner = 0.48;
  float ax = gl_TexCoord[0].x-0.5;
  float ay = gl_TexCoord[0].y-0.5;

  // blending factor, varying between 0.0 (at the border) and 1.0 (at the center of the square)
  float blend = smoothstep(-0.5, -inner, ay) * (1.0 - smoothstep(inner, 0.5, ay)) *
                smoothstep(-0.5, -inner, ax) * (1.0 - smoothstep(inner, 0.5, ax));

#if 1 // high contrast edge (dark edge on light surface / light edge on dark surface)
  float inv_blend = 1.0 - blend;
  vec3 col = blend * gl_Color.rgb + (sign(0.5 - length(vec3(gl_Color.rgb))) * vec3(0.2, 0.2, 0.2) + gl_Color.rgb) * inv_blend;
#else // alternatively: make color at edge darker
  vec3 col = (0.5 + 0.5*blend) * gl_Color.rgb;
#endif

  col = col + col * highlight.rgb;

  gl_FragColor = vec4(col.rgb, alpha * gl_Color.a);
}
