"--------------------------------------------------------------------------------\n"
"\n"
"  Function: ompt_get_device_time\n"
"\n"
"  Type Signature:\n"
"\n"
"    ompt_device_time_t ompt_get_device_time\n"
"    (\n"
"      ompt_device_t *device\n"
"    )\n"
"\n"
"  Description:\n"
"\n"
"    Return the current time on the specified device context using\n"
"    cuptiDeviceGetTimestamp.\n"
"\n"
"\n"
"--------------------------------------------------------------------------------\n"
"\n"
"  Function: ompt_translate_time\n"
"\n"
"  Type Signature:\n"
"\n"
"    double ompt_translate_time\n"
"    (\n"
"      ompt_device_t *device,\n"
"      ompt_device_time_t time\n"
"    )\n"
"\n"
"  Description:\n"
"\n"
"    Translate the time on the specified device context into a corresponding\n"
"    time value on the host device that is comparable with values returned by\n"
"    omp_get_wtime.\n"
"\n"
"--------------------------------------------------------------------------------\n"
"\n"
"  Function: ompt_target_set_trace_native\n"
"\n"
"  Type Signature:\n"
"\n"
"    int ompt_target_set_trace_native\n"
"    (\n"
"      ompt_device_t *device,\n"
"      int enable,\n"
"      int flags\n"
"    )\n"
"\n"
"  Description:\n"
"\n"
"    Enable or disable collection of a specific kind of activity\n"
"    record for a context using cuptiActivityEnableContext or\n"
"    cuptiActivityDisableContext.\n"
"\n"
"    The return codes for this routine have the following meaning:\n"
"        0	error\n"
"    	1	event will never occur\n"
"    	2	event may occur but no tracing is possible\n"
"    	3	event may occur and will be traced when convenient\n"
"    	4	event may occur and will be always be traced if event occurs\n"
"\n"
"--------------------------------------------------------------------------------\n"
"\n"
"  Function: ompt_start_trace\n"
"\n"
"  Type Signature:\n"
"\n"
"    int ompt_start_trace\n"
"    (\n"
"      ompt_device_t *device,\n"
"      ompt_callback_buffer_request_t request,\n"
"      ompt_callback_buffer_complete_t complete\n"
"    )\n"
"\n"
"  Description:\n"
"\n"
"    Register a buffer request callback and a buffer complete\n"
"    callback using cuptiActivityRegisterCallbacks. Enable and start\n"
"    trace collection.\n"
"\n"
"    This routine will return 1 if the operation succeeded and 0 otherwise.\n"
"\n"
"--------------------------------------------------------------------------------\n"
"\n"
"  Function: ompt_pause_trace\n"
"\n"
"  Type Signature:\n"
"\n"
"    int ompt_pause_trace\n"
"    (\n"
"      ompt_device_t *device,\n"
"      int begin_pause\n"
"    )\n"
"\n"
"  Description:\n"
"\n"
"    If begin_pause is non-zero, pause trace collection. Otherwise, resume\n"
"    trace collection. Note: an invocation of this routine will fail if trace\n"
"    collection was not previously enabled by ompt_start_trace.\n"
"\n"
"    This routine will return 1 if the operation succeeded and 0 otherwise.\n"
"\n"
"\n"
"--------------------------------------------------------------------------------\n"
"\n"
"  Function: ompt_stop_trace\n"
"\n"
"  Type Signature:\n"
"\n"
"    int ompt_stop_trace\n"
"    (\n"
"      ompt_device_t *device\n"
"    )\n"
"\n"
"  Description:\n"
"\n"
"    Stop trace collection. Note: an invocation of this routine will fail if\n"
"    trace collection was not previously enabled by ompt_start_trace.\n"
"\n"
"    This routine will return 1 if the operation succeeded and 0 otherwise.\n"
"\n"
"\n"
"--------------------------------------------------------------------------------\n"
"\n"
"  Function: ompt_get_record_type\n"
"\n"
"  Type Signature:\n"
"\n"
"    ompt_record_type_t ompt_get_record_type\n"
"    (\n"
"      ompt_buffer_t *buffer,\n"
"      ompt_buffer_cursor_t current\n"
"    )\n"
"\n"
"  Description:\n"
"\n"
"    Return an enumeration type that indicates whether the record at the\n"
"    current cursor position in the buffer is a native trace record,\n"
"    an OMPT trace record, or an invalid trace record.\n"
"\n"
"\n"
"--------------------------------------------------------------------------------\n"
"\n"
"  Function: ompt_get_record_native\n"
"\n"
"  Type Signature:\n"
"\n"
"    void *ompt_get_record_native\n"
"    (\n"
"      ompt_buffer_t *buffer,\n"
"      ompt_buffer_cursor_t current,\n"
"      ompt_id_t *host_op_id\n"
"    )\n"
"\n"
"  Description:\n"
"\n"
"    If the buffer contains a native trace record at the cursor position, this\n"
"    routine will return a pointer to a native record structure. If the function\n"
"    returns a non-null result, it will also set *host_op_id to the host-side\n"
"    identifier for the operation associated with the record.\n"
"\n"
"\n"
"--------------------------------------------------------------------------------\n"
"\n"
"  Function: ompt_get_record_abstract\n"
"\n"
"  Type Signature:\n"
"\n"
"    ompt_record_abstract_t *ompt_get_record_abstract\n"
"    (\n"
"      void *native_record\n"
"    )\n"
"\n"
"  Description:\n"
"\n"
"    Prepare an abstract that summarizes the information in a native trace\n"
"    record.\n"
"\n"
"--------------------------------------------------------------------------------\n"
"\n"
"  Function: ompt_advance_buffer_cursor\n"
"\n"
"  Type Signature:\n"
"\n"
"    int ompt_advance_buffer_cursor\n"
"    (\n"
"      ompt_buffer_t *buffer,\n"
"      size_t size,\n"
"      ompt_buffer_cursor_t current,\n"
"      ompt_buffer_cursor_t *next\n"
"    )\n"
"\n"
"  Description:\n"
"\n"
"    Return a cursor for the next record in the specified buffer\n"
"    given a cursor for the current record using cuptiActivityGetNextRecord.\n"
"\n"
"--------------------------------------------------------------------------------\n"
