/**
 * @file locale.h
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 15-09-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_LIBC_LOCALE_H
# define KFS_LIBC_LOCALE_H

# ifdef __cplusplus
extern "C" {
# endif

#define LC_ALL                 (1 << 0) // All of the locale
#define LC_ALL_MASK            ~LC_ALL
#define LC_ADDRESS             (1 << 1) // Formatting of addresses and geography-related items (*)
#define LC_ADDRESS_MASK        ~LC_ADDRESS
#define LC_COLLATE             (1 << 2) // String collation
#define LC_COLLATE_MASK        ~LC_COLLATE
#define LC_CTYPE               (1 << 3) // Character classification
#define LC_CTYPE_MASK          ~LC_CTYPE
#define LC_IDENTIFICATION      (1 << 4) // Metadata describing the locale (*)
#define LC_IDENTIFICATION_MASK ~LC_IDENTIFICATION
#define LC_MEASUREMENT         (1 << 5) // Settings related to measurements (metric versus US customary) (*)
#define LC_MEASUREMENT_MASK    ~LC_MEASUREMENT
#define LC_MESSAGES            (1 << 6) // Localizable natural-language messages
#define LC_MESSAGES_MASK       ~LC_MESSAGES
#define LC_MONETARY            (1 << 7) // Formatting of monetary values
#define LC_MONETARY_MASK       ~LC_MONETARY
#define LC_NAME                (1 << 8) // Formatting of salutations for persons (*)
#define LC_NAME_MASK           ~LC_NAME
#define LC_NUMERIC             (1 << 9) // Formatting of nonmonetary numeric values
#define LC_NUMERIC_MASK        ~LC_NUMERIC
#define LC_PAPER               (1 << 10) // Settings related to the standard paper size (*)
#define LC_PAPER_MASK          ~LC_PAPER
#define LC_TELEPHONE           (1 << 11) // Formats to be used with telephone services (*)
#define LC_TELEPHONE_MASK      ~LC_TELEPHONE
#define LC_TIME                (1 << 12) // Formatting of date and time values
#define LC_TIME_MASK           ~LC_TIME


typedef struct locale
{
	struct __locale_data *__locales[13];
	const unsigned short int *__ctype_b;
	const int *__ctype_tolower;
	const int *__ctype_toupper;
	const char *__names[13];
} locale;
typedef struct locale *locale_t;

typedef struct lconv {                /* Values in the "C" locale: */
	char *decimal_point;      /* "." */
	char *thousands_sep;      /* "" */
	char *grouping;           /* "" */
	char *mon_decimal_point;  /* "" */
	char *mon_thousands_sep;  /* "" */
	char *mon_grouping;       /* "" */
	char *positive_sign;      /* "" */
	char *negative_sign;      /* "" */
	char *currency_symbol;    /* "" */
	char  frac_digits;        /* CHAR_MAX */
	char  p_cs_precedes;      /* CHAR_MAX */
	char  n_cs_precedes;      /* CHAR_MAX */
	char  p_sep_by_space;     /* CHAR_MAX */
	char  n_sep_by_space;     /* CHAR_MAX */
	char  p_sign_posn;        /* CHAR_MAX */
	char  n_sign_posn;        /* CHAR_MAX */
	char *int_curr_symbol;    /* "" */
	char  int_frac_digits;    /* CHAR_MAX */
	char  int_p_cs_precedes;  /* CHAR_MAX */
	char  int_n_cs_precedes;  /* CHAR_MAX */
	char  int_p_sep_by_space; /* CHAR_MAX */
	char  int_n_sep_by_space; /* CHAR_MAX */
	char  int_p_sign_posn;    /* CHAR_MAX */
	char  int_n_sign_posn;    /* CHAR_MAX */
} lconv_t;

char *setlocale(int category, const char *locale);

lconv_t *localeconv(void);

# ifdef __cplusplus
}
# endif

#endif // KFS_LIBC_LOCALE_H
