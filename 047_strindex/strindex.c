/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t) {
  char *s0 = s;
  char *sS = s;
  char *t0 = t;

  while (*s0) {
    s = s0;
    t = t0;

    while (*t != '\0' && *s == *t) {
      s++;
      t++;
    };

    if (t > t0 && *t == '\0')
      return s - sS - (t - t0);

    s0++;
  }

  return -1;
}
