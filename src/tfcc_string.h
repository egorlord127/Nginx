typedef struct {
    size_t      len;
    u_char     *data;
}tfcc_str_t;

typedef struct {
    tfcc_str_t   key;
    tfcc_str_t   value;
}tfcc_keyval_t;

typedef struct {
    unsigned    len: 28;
    unsigned    valid: 1;
    unsigned    no_cacheable: 1;
    unsigned    not_found: 1;
    unsigned    escape: 1;
    
    u_char  *data;
}

#define tfcc_string(str)         {sizeof(str) - 1, (u_char *)str}
#define tfcc_null_string         {0, NULL}
#define tfcc_str_set(str, text)  (str)->len = sizeof(text) - 1; (str)->data = (u_char *) text
#define tfcc_str_null(str)       (str)->len = 0; (str)->data = NULL

#define tfcc_tolower(c)          (u_char *) ((c >= 'A' && c <= 'Z')? ((c | 0x20) : c)
#define tfcc_toupper(c)          (u_char *) ((c >= 'a' && c <= 'a')? ((c & ~0x20) : c)

void tfcc_strlow(u_char *dst, u_char *src, size_t n);

#define tfcc_strncmp(s1, s2, n)  strncmp((const char *) s1, (const char *) s2, n)

#define tfcc_strcmp(s1, s2)      strcmp((const char *) s1, (const char *) s2)

#define tfcc_strstr(s1, s2)      strstr(s1, s2)
#define tfcc_strlen(s)           strlen(s)
#define tfcc_strchr(s1, c)       strchr((const char *) s1, (int) c)



