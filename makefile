NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

LIBFT_DIR = src/libft/
LIBFT_FILES = libft.a
LIBFT_INCLUDES = $(LIBFT_DIR)includes/
LIBFT = $(LIBFT_DIR)$(LIBFT_FILES)

PRINT_DIR := src/printing/
PRINT_FILES := print_stacks.c \
			   print_stacks_horizontal.c \
			   print_stacks_index.c \

PARSING_DIR := src/parsing/
PARSING_FILES := ft_atoi_err.c \
				 parsing.c \
				
INSTRUCTION_DIR := src/instruction/
INSTRUCTION_FILES :=  inst_pa.c \
					  inst_pb.c \
					  inst_r.c \
					  inst_r_both.c \
					  inst_rr.c \
					  inst_rr_both.c \
					  inst_s.c \

SORTING_DIR := src/sorting_algorithm/
SORTING_FILES := sort_stack.c \
				 sort_three.c \
				 selection_sort.c \
				 bubble_sort.c \
				 insertion_sort.c \
				 merge_sort.c \
				 merge_sort_utils.c \
				 merge_sort_push_case.c \
				 indexing.c \
				 radix_sort.c \
				 radix_sort_ternary.c \
				 cost_sort.c \
				 cost_sort_utils.c \
				 cost_sort_pushs.c \


FILES_INCLUDES := includes/
C_FILES := $(NAME).c \
		   $(addprefix $(PRINT_DIR), $(PRINT_FILES)) \
		   $(addprefix $(PARSING_DIR), $(PARSING_FILES)) \
		   $(addprefix $(INSTRUCTION_DIR), $(INSTRUCTION_FILES)) \
		   $(addprefix $(SORTING_DIR), $(SORTING_FILES)) \
		   $(addprefix $(LISTS_UTILS_DIR), $(LISTS_UTILS_FILES)) \

OBJ_DIR := .obj/
OBJ_FILES := $(addprefix $(OBJ_DIR), $(C_FILES:.c=.o))
DEP_FILES := $(OBJ_FILES:.o=.d)

.PHONY: all clean fclean re exec

all: git makelibft $(NAME)

makelibft:
	$(MAKE) -C src/libft/

git:
	git submodule update --init --remote --recursive

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) -I $(FILES_INCLUDES) -I $(LIBFT_INCLUDES) $^ $(LIBFT) -o $@ 

-include $(DEP_FILES)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)$(PRINT_DIR) $(OBJ_DIR)$(PARSING_DIR) $(OBJ_DIR)$(INSTRUCTION_DIR) $(OBJ_DIR)$(SORTING_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c -I $(FILES_INCLUDES) -I $(LIBFT_INCLUDES) $< -o $@

$(OBJ_DIR)$(PARSING_DIR):
	mkdir -p $@

$(OBJ_DIR)$(INSTRUCTION_DIR):
	mkdir -p $@

$(OBJ_DIR)$(PRINT_DIR):
	mkdir -p $@

$(OBJ_DIR)$(SORTING_DIR):
	mkdir -p $@

clean:
	$(MAKE) -C src/libft clean
	rm -rf $(OBJ_DIR)

fclean:
	$(MAKE) -C src/libft fclean
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

exec: 
	./$(NAME) 50 50

exec2: 
	./$(NAME)  7 8 4 9 3 2 10 5 1 6
	
test_leak:
	valgrind ./push_swap "37 66 499 481 250 293 494 268 167 349 93 407 467 283 453 305 142 190 52 471 342 346 205 165 488 397 482 197 77 192 284 299 270 387 458 473 170 489 388 136 290 405 180 251 203 256 318 415 121" 279 340 334 2 492 246 297 184 459 296 91 119 218 442 236 172 344 451 245 295 302 374 61 466 196 97 232 179 308 371 72 43 173 219 44 263 38 152 213 129 26 195 370 425 377 19 42 411 359 382 431 120 139 465 426 36 362 "289 375 146 421 35 124 27 317 347 262 326 363 348 14 131 135 113 198 373 118 483 313 480 22 211 226 112" 369 361 288 484 403 228 158 227 448 40 257 447 419 128 169 10 432 428 446 354 178 82 351 303 193 20 88 337 34 338 1 427 420 166 6 68 188 306 235 79 87 440 24 108 242 267 247 409 434 449 231 321 48 271 450 102 202 104 41 33 330 84 103 156 85 269 89 384 116 324 32 94 51 461 323 54 445 133 479 160 298 144 153 436 148 182 412 25 92 234 75 126 285 17 476 497 30 81 261 319 229 372 410 452 70 130 76 243 150 50 241 155 327 168 490 310 4 391 366 149 368 31 333 16 95 464 115 224 314 65 455 341 63 274 367 441 154 240 365 210 443 379 96 47 21 470 331 312 62 329 390 15 23 266 378 207 123 418 328 414 491 157 238 223 438 143 164 495 49 380 498 220 45 177 493 200 194 255 307 304 260 237 383 29 454 39 404 287 475 28 339 83 276 322 253 254 424 259 358 394 393 183 69 71 249 11 417 463 406 457 487 413 3 360 59 398 175 67 199 98 132 395 422 496 187 386 161 385 277 55 478 343 291 239 435 189 468 252 74 444 275 311 355 215 292 107 12 456 272 101 352 281 162 244 90 140 109 209 147 399 416 186 300 401 316 389 309 141 176 477 138 185 423 472 163 408 206 248 332 278 462 64 500 201 7 114 381 181 364 353 18 486 439 56 233 110 191 159 86 8 99 392 5 105 212 315 125 53 357 151 78 225 214 258 174 301 273 221 100 356 336 282 60 58 222 430 400 335 145 13 204 350 280 265 171 474 376 437 264 57 429 137 345 485 217 294 216 433 111 230 402 469 134 320 80 286 9 325 117 460 46 396 73 122 127 106 208
