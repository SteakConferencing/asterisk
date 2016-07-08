/*! \file
 * \brief 8-bit data
 *
 * Copyright (C) 2014, Lorenzo Miniero
 *
 * Distributed under the terms of the GNU General Public License
 *
 */

#define OPUS_FRAME_SIZE 960
#define OPUS_DEFAULT_SAMPLE_RATE 48000

/* Opus, a 20ms sample */
static uint8_t ex_opus[] = {
	0x4b, 0x41, 0x25, 0x0b, 0xe4, 0x55, 0xc6, 0x74,
	0xda, 0xbb, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static struct ast_frame *opus_sample(void)
{
	static struct ast_frame f = {
		.frametype = AST_FRAME_VOICE,
		.datalen = sizeof(ex_opus),
		.samples = OPUS_FRAME_SIZE, 
		.mallocd = 0,
		.offset = 0,
		.src = __PRETTY_FUNCTION__,
		.data.ptr = ex_opus,
	};

	f.subclass.format = ast_format_opus;

	return &f;
}

struct opus_attr {
        unsigned int maxbitrate;                /* Default 64-128 kb/s for FB stereo music */
        unsigned int maxplayrate                /* Default 48000 */;
        unsigned int minptime;              /* Default 3, but it's 10 in format.c */
        unsigned int stereo;                /* Default 0 */
        unsigned int cbr;                       /* Default 0 */
        unsigned int fec;                       /* Default 0 */
        unsigned int dtx;                       /* Default 0 */
        unsigned int spropmaxcapturerate;       /* Default 48000 */
        unsigned int spropstereo;               /* Default 0 */
};

