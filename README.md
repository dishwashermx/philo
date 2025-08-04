# Philosophers 🧠🍝

_“I never thought philosophy would be so deadly.”_

This project is part of the 42 curriculum. It simulates the classic **Dining Philosophers Problem**, focusing on **threading**, **mutexes**, and **race-condition prevention** in C.

---

## 📌 Objective

Build a program that behaves like a simulation of philosophers eating, sleeping, thinking, and dying if not fed in time. You'll learn about:

- **POSIX threads**
- **Mutex locks**
- **Concurrent behavior and race conditions**
- **Time-sensitive synchronization**

---

## ⚙️ Compilation

Ensure your files are in the `philo/` directory.

```bash
make
```

Available rules:
- `make` / `make all`: compile the project
- `make clean`: remove object files
- `make fclean`: remove all compiled binaries and object files
- `make re`: full clean and rebuild

---

## 🚀 Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Example:

```bash
./philo 5 800 200 200
```

- 5 philosophers
- 800 ms before dying of hunger
- 200 ms to eat
- 200 ms to sleep

Optional:
```bash
./philo 5 800 200 200 7
```
The simulation stops when each philosopher has eaten at least 7 times.

---

## 📋 Log Format

Each log follows this format:

```
[timestamp_in_ms] [philo_number] [status]
```

Examples:
```
000031 3 has taken a fork
000032 3 is eating
000232 3 is sleeping
000433 3 is thinking
```

Death must be printed **within 10ms** of detection.

---

## ✅ Project Rules

- No global variables
- No memory leaks
- All state changes must be **mutex-protected**
- All forks must be represented by a **mutex**
- Use only allowed functions:
  - `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`

---

## 🧪 Mandatory Features

- Each philosopher is a **separate thread**
- One **mutex per fork**
- Philosophers follow a strict lifecycle:  
  `think → take forks → eat → put forks → sleep → repeat`
- The simulation stops:
  - When a philosopher dies
  - OR all philosophers eat the required number of times (if given)

---

## 🏆 Bonus (if mandatory is perfect)

If implemented in `philo_bonus/`, you may:
- Replace threads with **processes**
- Replace mutexes with **semaphores**
- Handle all forks as a shared semaphore pool
- Use `fork`, `kill`, `sem_open`, `sem_wait`, `sem_post`, etc.

---

## 👨‍💻 Author

**ghwa** – 42KL  
Email: `ghwa@student.42kl.edu.my`

---

> _May your philosophers eat well... and not die._
