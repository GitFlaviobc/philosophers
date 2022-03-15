# Philosophers Dinner

<h1 name ="content" align = "center">📋 Table of contents</h1>
<p align = "center">
  <a href = "#intro">Intro</a> -
  <a href = "#goal">Goal</a> -
  <a href = "#tec">Tecnology</a> -
  <a href = "#function">Functionality</a> -
  <a href = "#how">How to use</a> -
  <a href = "#test">Tests</a> -
  <a href = "#update">Update</a> -
  <a href = "#author">Author</a>
</p>

<a name="intro"/> <h2> Intro </h2> </a>
- This is a project about sharing resources.
- On this project I learned about threads, mutex, data racing and about semaphores.
- The concept of the dinner is used to show how threads can share resources and how to have control of what each thread is doing.
- The code does not use semaphores and the logic would have to change tu use it, once it uses process. But I learned how they work and how I would have to do.
<p></p>
<a href = "#content">📋</a>

<a name="goal"/> <h2> 🎯 Goal </h2> </a>
- The dinner happens on a round table.
- Each thread will be a philosopher.
- Each philosopher has a fork.
- To eat, each philosopher needs its own fork and the fork of the next philosopher. And the last philosopher uses its own fork and the fork of the first philosopher.
- Each philosopher needs to eat, sleep, think.
- If a philosopher cannot eat before the time to eat ends, the philoshper dies and the dinner is over. The time to eat is reseted after every meal.
- If all philosophers eat the times they need the dinner is over.
- If there is no limit of how many times they need to eat, the dinner will not end if the philosophers are always able to eat before the time.
- Mutexes will be used to lock resources, avoiding data racing and making sure each philosopher is doing the right action.
- One extra thread is used to control the dinner from outside the table, checking every time if any philoshopher died or if they all ate the meals needed. If yes, it will set the dinner to finished.
- Before doing the actions, the philosophers are checking if the dinner is finished or not.
- All the philosphers actions are printed on the terminal with the current dinner timer in miliseconds and the philosopher number.
- To make sure the philosophers are able to take the forks they need, the even numbers philosophers (1,3,5....) are delayed a little in the beginning, so the even numbers (2,4,6...) can take the forks they need and put back for the other philosophers, during the time they are thinking and sleeping.

- With semaphores the idea will be different, where all the forks will be in the center of the table and whoever gets two can go eat. But the other rules of the dinner are the same.
<p></p>
<a href = "#content">📋</a>

<a name="tec"/> <h2> 🛠️ Tecnology </h2> </a>
- Language: C
- VS code
- WSL ubuntu
- Norminette 42 (code norm used by école 42)
<p></p>
<a href = "#content">📋</a>

<a name="function"/> <h2> 📚 Functionality </h2> </a>

![Push Logic](https://github.com/GitFlaviobc/Push_Swap/blob/master/Images/Logic.JPG)
![Push Test](https://github.com/GitFlaviobc/Push_Swap/blob/master/Images/PushSwap.gif)

<p></p>
<a href = "#content">📋</a>

<a name="how"/> <h2> 📖 How to use </h2> </a>

- Clone the repository
```bash
git clone https://github.com/GitFlaviobc/Push_Swap.git
```
- to create the push_swap (Inside Project folder)
```bash
make
```
or
```bash
make all
```
- to delete all obj (.o) files created
```bash
make clean
```
 - to delete all created files
```bash
make fclean
```
 - to delete all files and recreate the push_swap
```bash
make re
```
- Simple test: Save the movements in a file and save the number of movements into another file - 1k numbers
```bash
./push_swap -342 -322 -102 312 -383 -305 416 296 442 -234 -19 -387 -476 -439 -402 276 -211 334 402 -58 139 -460 458 273 -84 -411 26 74 208 -359 -446 284 -384 -275 -487 -233 431 229 -181 -92 -113 -7 222 29 -171 367 471 -64 -276 -196 344 480 259 -401 338 -242 113 224 -435 397 204 -39 271 237 -418 128 -311 192 258 -249 153 438 -147 292 -41 -226 57 -293 38 223 -51 255 484 31 441 149 277 34 154 461 -14 109 -235 440 234 115 185 333 101 412 -354 -101 436 -204 61 -284 198 -324 -266 236 -443 279 -339 -362 -46 98 73 -301 394 174 -454 319 391 324 303 486 -136 300 -79 -345 -484 4 393 -285 43 -186 47 354 389 341 238 132 78 -332 -464 104 342 -333 -449 -206 -26 -77 -159 -474 -463 -70 -131 -112 -21 -90 478 -72 340 -318 -358 138 -432 -212 371 -219 -96 -391 274 499 466 470 -27 183 -250 -151 -172 -335 -405 129 401 323 -279 -34 -376 218 313 197 176 64 362 -396 -74 -347 378 -365 207 -479 -485 -123 -237 -160 37 206 196 -444 347 -417 -270 -373 445 288 -457 282 -459 395 -217 414 -138 482 219 -472 -272 318 152 158 178 241 165 -317 190 469 -75 481 -140 -3 320 -274 -498 -448 -184 -295 -286 -53 240 156 -25 322 417 265 349 36 345 -367 -128 -278 490 420 -97 157 -61 -288 307 -118 -176 -11 297 -178 463 253 180 346 -71 -338 186 -456 443 -353 -232 -100 275 264 161 302 -290 170 483 -431 148 413 -438 422 -374 -239 285 41 199 473 16 -360 321 -81 359 249 -95 -105 25 -455 150 372 217 -141 9 -325 -73 325 35 -177 -461 316 -55 -231 133 360 105 -497 386 215 -441 225 380 202 -94 -302 -149 -328 -422 -111 23 159 11 -144 -330 -280 95 311 -409 -166 460 195 -139 309 -408 136 163 53 -475 -395 -319 433 49 -36 -104 387 -380 -429 -213 295 -248 -334 398 91 -481 -155 -341 160 -296 348 66 -473 250 -203 168 -246 -351 -214 -419 -357 -364 -18 -4 182 -321 -180 -462 -428 -273 -412 332 304 -467 48 -433 -85 299 280 134 127 498 -308 -300 492 456 162 256 -28 177 -197 -331 405 -251 -108 188 -416 252 65 424 233 33 -267 143 -247 381 89 -320 -483 453 449 -430 -442 350 452 355 69 88 72 485 -32 -348 -355 -399 -29 -185 145 314 -253 -30 142 -292 187 363 455 205 -312 -93 343 462 -375 -156 -366 328 -470 -40 247 -277 -106 421 -450 166 382 230 270 -173 -114 -182 487 -130 -480 -394 -174 40 -381 -382 476 357 -240 228 -42 -371 -17 13 63 226 -9 -368 450 18 377 -168 84 459 97 -323 434 17 -110 -120 -306 209 -264 124 123 155 42 -45 -299 497 384 268 171 -162 -337 -420 -245 -170 2 119 -215 -143 -200 -406 437 278 388 173 -491 364 -316 435 -415 184 51 -390 -372 55 131 290 -294 151 -228 231 426 -190 373 27 439 269 12 283 193 146 -445 7 -16 93 -103 90 -271 191 409 -150 -451 -490 121 329 28 385 -35 32 -117 -192 -310 -403 390 -469 -252 -37 352 58 -421 -468 494 488 -452 -314 477 375 -50 125 -24 -495 106 221 -52 -482 -499 102 -289 232 96 406 425 -229 -265 126 172 -287 379 194 374 370 281 -386 52 -424 -137 308 -1 175 353 -22 -244 432 -66 -344 135 -65 111 -48 -157 200 -187 5 -13 -281 -361 82 -207 263 -87 -209 -194 -116 423 428 54 77 -83 -69 -125 20 -129 418 317 99 467 56 361 287 -12 179 -427 108 -423 59 201 -298 -466 181 -327 -230 147 448 -154 -208 -122 -379 -191 -163 262 76 -389 -297 298 -291 451 260 1 -407 -20 -54 -336 -257 -205 -388 19 356 -152 21 -486 -88 -255 235 427 -221 8 -161 -458 144 -201 6 -393 103 -303 -370 251 24 -188 -349 141 -259 -225 -33 266 331 -392 110 -148 415 -377 429 -124 -119 493 -315 -132 -343 254 396 -227 79 -492 -326 -282 -223 -6 310 407 -437 140 291 474 335 14 213 -453 -340 465 -478 -133 -363 -414 114 479 403 289 -23 -134 -63 75 -356 30 339 -385 -98 -99 -397 46 -224 -447 212 15 -195 294 -216 -175 83 242 -164 330 -398 44 -404 400 62 -254 243 107 -89 -283 -47 -183 -436 489 0 -210 327 220 211 216 365 293 301 70 -38 86 457 -115 -269 336 -500 -86 -43 -126 245 45 -198 100 -2 286 -127 368 -135 -146 118 430 351 -62 408 399 -80 446 203 -400 468 -107 246 -10 475 130 227 50 92 -78 261 -471 272 -165 85 369 -60 383 410 -31 -76 -496 81 -202 94 -261 -262 -352 267 248 444 164 87 210 -440 -241 -199 -142 472 -413 -477 306 -307 366 -304 -493 -68 392 71 60 68 491 189 116 326 -145 -218 496 -426 -67 -238 244 -189 464 -91 -256 -158 -489 -222 67 -313 376 -8 337 -329 -309 -56 137 120 -350 305 -193 169 -425 447 495 -236 -494 -109 -169 -258 80 112 454 -15 257 358 3 10 -260 -243 -57 117 -434 214 419 39 239 -346 -167 315 -465 -59 -49 500 -179 -263 -220 -369 -378 -121 -44 -82 -5 -268 -153 -488 167 122 411 22 404 > result.txt && echo The Total is: >> total.txt && < result.txt wc -l >> total.txt
```
<p></p>
<a href = "#content">📋</a>

<a name="test"/> <h2> 👨‍💻 Tests </h2> </a>
- You can generate random numbers in here for manual tests: [Random](https://www.random.org/integer-sets/)
- I used this tester to get faster results: [Tester](https://github.com/laisarena/push_swap_tester)
<p></p>
<a href = "#content">📋</a>

<a name="update"/> <h2> 🆙 Updates </h2> </a>
- The code I sent to evaluation will be kept the same. Any update will be on the update folder.⚠️🚧
<p></p>
<a href = "#content">📋</a>

<a name="author"/> <h2> 😀 Author </h2> </a>
Name: Flávio Bonini Campos
<p></p>

[![Linkedin](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/flaviobc88/)
<p></p>
<a href = "#content">📋</a>
<p></p>
