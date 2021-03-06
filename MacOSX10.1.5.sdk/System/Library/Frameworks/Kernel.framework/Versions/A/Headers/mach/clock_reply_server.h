#ifndef	_clock_reply_server_
#define	_clock_reply_server_

/* Module clock_reply */

#include <string.h>
#include <mach/ndr.h>
#include <mach/boolean.h>
#include <mach/kern_return.h>
#include <mach/notify.h>
#include <mach/mach_types.h>
#include <mach/message.h>
#include <mach/mig_errors.h>
#include <mach/port.h>

#ifdef AUTOTEST
#ifndef FUNCTION_PTR_T
#define FUNCTION_PTR_T
typedef void (*function_ptr_t)(mach_port_t, char *, mach_msg_type_number_t);
typedef struct {
        char            *name;
        function_ptr_t  function;
} function_table_entry;
typedef function_table_entry 	*function_table_t;
#endif /* FUNCTION_PTR_T */
#endif /* AUTOTEST */

#ifndef	clock_reply_MSG_COUNT
#define	clock_reply_MSG_COUNT	1
#endif	/* clock_reply_MSG_COUNT */

#include <mach/std_types.h>
#include <mach/mach_types.h>

#ifdef __BeforeMigServerHeader
__BeforeMigServerHeader
#endif /* __BeforeMigServerHeader */

/* typedefs for all requests */

	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t alarm_code;
		alarm_type_t alarm_type;
		mach_timespec_t alarm_time;
	} __Request__clock_alarm_reply_t;


/* union of all requests */

union __RequestUnion__clock_reply_subsystem {
	__Request__clock_alarm_reply_t Request_clock_alarm_reply;
};
/* typedefs for all replies */

	typedef struct {
		mach_msg_header_t Head;
		NDR_record_t NDR;
		kern_return_t RetCode;
	} __Reply__clock_alarm_reply_t;


/* union of all replies */

union __ReplyUnion__clock_reply_subsystem {
	__Reply__clock_alarm_reply_t Reply_clock_alarm_reply;
};

/* SimpleRoutine clock_alarm_reply */
#ifdef	mig_external
mig_external
#else
extern
#endif	/* mig_external */
kern_return_t clock_alarm_reply
(
	clock_reply_t alarm_port,
	kern_return_t alarm_code,
	alarm_type_t alarm_type,
	mach_timespec_t alarm_time
);

extern boolean_t clock_reply_server(
		mach_msg_header_t *InHeadP,
		mach_msg_header_t *OutHeadP);

extern mig_routine_t clock_reply_server_routine(
		mach_msg_header_t *InHeadP);


/* Description of this subsystem, for use in direct RPC */
extern const struct clock_reply_subsystem {
	struct subsystem *	subsystem;	/* Reserved for system use */
	mach_msg_id_t	start;	/* Min routine number */
	mach_msg_id_t	end;	/* Max routine number + 1 */
	unsigned int	maxsize;	/* Max msg size */
	vm_address_t	base_addr;	/* Base ddress */
	struct routine_descriptor	/*Array of routine descriptors */
		routine[1];
} clock_reply_subsystem;


#ifndef subsystem_to_name_map_clock_reply
#define subsystem_to_name_map_clock_reply \
    { "clock_alarm_reply", 3125107 }
#endif

#ifdef __AfterMigServerHeader
__AfterMigServerHeader
#endif /* __AfterMigServerHeader */

#endif	 /* _clock_reply_server_ */
