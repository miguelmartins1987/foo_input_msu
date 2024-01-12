#include "pch.h"
#include "stdint.h"

#ifndef __INPUT_MSU_H__
#define __INPUT_MSU_H__


class input_msu : public input_stubs
{
private:
	service_ptr_t<file>		m_File;
	pfc::array_t<t_uint8>	m_DecodeBuffer;

	uint32_t				m_PcmFileLength;
	uint32_t				m_PcmFileLoop;
	uint32_t				m_PcmFilePos;
	pfc::array_t<t_uint8>	m_PcmFile;			// in-memory copy of PCM file
	pfc::string8			m_PcmPath;			// PCM file path
public:
	input_msu();
	~input_msu();

	static bool g_is_our_path(const char* p_path, const char* p_extension) {
		return (::stricmp_utf8(p_extension, "pcm") == 0);
	}

	static const char* g_get_name() {
		return "msu";
	}

	static GUID g_get_guid() {
		// {99BF15A1-1A5F-4B97-8836-154FCAEDF8C7}
		static const GUID guid = { 0x99bf15a1, 0x1a5f, 0x4b97, { 0x88, 0x36, 0x15, 0x4f, 0xca, 0xed, 0xf8, 0xc7 } };
		return guid;
	}

	void open(service_ptr_t<file> p_filehint, const char* p_path, t_input_open_reason p_reason, abort_callback& p_abort);
	void get_info(file_info& p_info, abort_callback& p_abort);
	void decode_initialize(unsigned int p_flags, abort_callback& p_abort);
	bool decode_run(audio_chunk& p_chunk, abort_callback& p_abort);
	void decode_seek(double p_seconds, abort_callback& p_abort);
	bool decode_can_seek() { return true; }

	t_filestats get_file_stats(abort_callback& p_abort) { return m_File->get_stats(p_abort); }
	t_filestats2 get_stats2(uint32_t f, abort_callback& a) { return m_File->get_stats2_(f, a); }
	void decode_on_idle(abort_callback& p_abort) { m_File->on_idle(p_abort); }
	bool decode_get_dynamic_info(file_info& p_out, double& p_timestamp_delta) { return false; }
	bool decode_get_dynamic_info_track(file_info& p_out, double& p_timestamp_delta) { return false; }
	static bool g_is_our_content_type(const char* p_content_type) { return false; }
	void retag(const file_info& p_info, abort_callback& p_abort) {}
	void remove_tags(abort_callback& p_abort) {}
};

#endif /* __INPUT_SNESAPU___ */