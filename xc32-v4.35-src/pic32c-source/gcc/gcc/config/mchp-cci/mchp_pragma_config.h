#if defined(TARGET_IS_PIC32C)

#define MCHP_CONFIGURATION_DATA_FILENAME "configuration.data"
#define MCHP_CONFIGURATION_HEADER_MARKER                                      \
  "Microchip Configuration Word Definitions: "
#define MCHP_CONFIGURATION_HEADER_VERSION "0001"
#define MCHP_CONFIGURATION_HEADER_SIZE                                        \
  (sizeof (MCHP_CONFIGURATION_HEADER_MARKER) + 5)

#else

#define MCHP_CONFIGURATION_DATA_FILENAME "configuration.data"
#define MCHP_CONFIGURATION_HEADER_MARKER                                      \
  "Daytona Configuration Word Definitions: "
#define MCHP_CONFIGURATION_HEADER_VERSION "0001"
#define MCHP_CONFIGURATION_HEADER_SIZE                                        \
  (sizeof (MCHP_CONFIGURATION_HEADER_MARKER) + 5)

#endif

#define MCHP_ALLOW_INTEGER_CONFIGVALUE 1

#define MCHP_WORD_MARKER "CWORD:"
#define MCHP_SETTING_MARKER "CSETTING:"
#define MCHP_VALUE_MARKER "CVALUE:"
#define MCHP_WORD_MARKER_LEN (sizeof (MCHP_WORD_MARKER) - 1)
#define MCHP_SETTING_MARKER_LEN (sizeof (MCHP_SETTING_MARKER) - 1)
#define MCHP_VALUE_MARKER_LEN (sizeof (MCHP_VALUE_MARKER) - 1)

/* Pretty much arbitrary max line length for the config data file.
   Anything longer than this is either absurd or a bogus file. */
#define MCHP_MAX_CONFIG_LINE_LENGTH 1024

#ifndef CLEAR_REST_OF_INPUT_LINE
#define CLEAR_REST_OF_INPUT_LINE()                                            \
  do                                                                          \
    {                                                                         \
      int t;                                                                  \
      tree tv;                                                                \
      do                                                                      \
        {                                                                     \
          t = pragma_lex (&tv);                                               \
        }                                                                     \
      while (t != CPP_EOF);                                                   \
    }                                                                         \
  while (0);
#endif

struct mchp_config_value
{
  char *name;
  char *description;
  unsigned value;
  struct mchp_config_value *next;
};

struct mchp_config_setting
{
  char *name;
  char *description;
  unsigned mask;
  struct mchp_config_value *values;
  struct mchp_config_setting *next;
};

struct mchp_config_region
{
  unsigned size;
  unsigned address;
  unsigned mask;
  unsigned default_value;
  struct mchp_config_setting *settings;
};

struct mchp_config_specification
{
  struct mchp_config_region *region; /* the definition of the region
					this value is referencing */
  unsigned value;           /* the value of the region to put to the device */
  unsigned referenced_bits; /* the bits which have been explicitly specified
                              i.e., have had a setting = value pair in a
                              config pragma */
  struct mchp_config_specification *next;
};

extern struct mchp_config_specification *mchp_configuration_values;
extern int mchp_load_configuration_definition (const char *fname);
extern void
mchp_handle_configuration_setting (const char *name,
                                   const unsigned char *value_name);
