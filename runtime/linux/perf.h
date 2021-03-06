/* -*- linux-c -*- 
 * Perf Header File
 * Copyright (C) 2006-2012 Red Hat Inc.
 *
 * This file is part of systemtap, and is free software.  You can
 * redistribute it and/or modify it under the terms of the GNU General
 * Public License (GPL); either version 2, or (at your option) any
 * later version.
 */

#ifndef _PERF_H_
#define _PERF_H_

/** @file perf.h
 * @brief Header file for performance monitoring hardware support
 */

struct stap_perf_probe {
        struct perf_event_attr attr;
	perf_overflow_handler_t callback;
	const struct stap_probe * const probe;
        int per_thread;
        union
	{
	  /* per-cpu data. allocated with _stp_alloc_percpu() */
	  struct perf_event **events;
	  struct 
	  {
	    /* per-task data. allocated by perf_event_create_kernel_counter */
	    struct perf_event *per_thread_event;
	    struct stap_task_finder_target tgt;
	  } t;
	} e;
};

static long _stp_perf_init (struct stap_perf_probe *stp, struct task_struct* task);

static void _stp_perf_del (struct stap_perf_probe *stp);

#endif /* _PERF_H_ */
