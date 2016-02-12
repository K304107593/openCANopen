#ifndef CANOPEN_DUMP_H_
#define CANOPEN_DUMP_H_

#define CO_DUMP_PDO_FILTER_SHIFT 8
#define CO_DUMP_FILTER_MASK 0x0000fffe

enum co_dump_options {
	CO_DUMP_TCP = 1,

	CO_DUMP_FILTER_NMT = 1 << 1,
	CO_DUMP_FILTER_SYNC = 1 << 2,
	CO_DUMP_FILTER_TIMESTAMP = 1 << 3,
	CO_DUMP_FILTER_EMCY = 1 << 4,
	CO_DUMP_FILTER_SDO = 1 << 5,
	CO_DUMP_FILTER_HEARTBEAT = 1 << 6,

	CO_DUMP_FILTER_PDO1 = 1 << (CO_DUMP_PDO_FILTER_SHIFT + 0),
	CO_DUMP_FILTER_PDO2 = 1 << (CO_DUMP_PDO_FILTER_SHIFT + 1),
	CO_DUMP_FILTER_PDO3 = 1 << (CO_DUMP_PDO_FILTER_SHIFT + 2),
	CO_DUMP_FILTER_PDO4 = 1 << (CO_DUMP_PDO_FILTER_SHIFT + 3),

	CO_DUMP_FILTER_PDO = CO_DUMP_FILTER_PDO1 | CO_DUMP_FILTER_PDO2
			   | CO_DUMP_FILTER_PDO3 | CO_DUMP_FILTER_PDO4,
};

int co_dump(const char* addr, enum co_dump_options options);

#endif /*  CANOPEN_DUMP_H_ */
