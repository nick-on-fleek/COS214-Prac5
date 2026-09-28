# CampusGuard – COS 214 Practical 5

Emergency response coordination platform (C++11).

## Team
- Member 1: u25443705
- Member 2: u25108582
- Member 3: u25245962

## Build and run (Docker)

```
docker compose up --build
```

## Build and run (local)

```
make
./campusguard
```

## Valgrind / GDB

```
docker compose run --rm campusguard valgrind --leak-check=full --show-leak-kinds=all ./campusguard
```

## Layout
- `src/` – all source files
- `Makefile`, `Dockerfile`, `docker-compose.yml`
