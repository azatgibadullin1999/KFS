ENTRY(_start)

SECTIONS
{
	. = 1M;

	_kfs_sections_begin = .;
	.text BLOCK(4K) : ALIGN(4K)
	{
		_text_begin = .;
		*(.multiboot)
		*(.text)
		_text_end = .;
	}

	.rodata BLOCK(4K) : ALIGN(4K)
	{
		_rodata_begin = .;
		*(.rodata)
		_rodata_end = .;
	}

	.data BLOCK(4K) : ALIGN(4K)
	{
		_data_begin = .;
		*(.data)
		_data_end = .;
	}

	.bss BLOCK(4K) : ALIGN(4K)
	{
		_bss_begin = .;
		*(COMMON)
		*(.bss)
		_bss_end = .;
	}
	_kfs_sections_end = .;
}