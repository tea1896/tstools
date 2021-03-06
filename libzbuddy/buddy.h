/* vim: set tabstop=8 shiftwidth=8:
 * name: buddy.h
 * funx: buddy memory pool, to avoid malloc and free from OS frequently
 * 2013-03-09, ZHOU Cheng, modularized
 * 2012-11-02, manuscola.bean@gmail.com, optimized from https://github.com/wuwenbin/buddy2
 */

#ifndef _BUDDY_H
#define _BUDDY_H

#ifdef __cplusplus
extern "C" {
#endif

#define BUDDY_ORDER_MAX (8 * sizeof(size_t))

intptr_t buddy_create(size_t order_max, size_t order_min);
int buddy_destroy(intptr_t id);
int buddy_init(intptr_t id);
int buddy_status(intptr_t id, int enable, const char *hint); /* for debug */

void *buddy_malloc(intptr_t id, size_t size);
void *buddy_realloc(intptr_t id, void *ptr, size_t size); /* need to be test */
void buddy_free(intptr_t id, void *ptr);

#ifdef __cplusplus
}
#endif

#endif /* _BUDDY_H */
