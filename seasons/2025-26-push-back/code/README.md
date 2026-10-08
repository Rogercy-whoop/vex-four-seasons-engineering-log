# 2025–26 autonomous code

I wrote every autonomous routine for 117V this season, in C++ with VEXcode Pro V5. A second programmer on the team was learning and assisted me.

| File | Lines | What it is |
|---|---|---|
| [`autons.cpp`](autons.cpp) | 392 | Every autonomous routine, and the PID gains and exit conditions they run with |
| [`autofunction.cpp`](autofunction.cpp) | 82 | Helpers the routines call: collect and store, score high, score in the middle goal, stop |
| [`user.cpp`](user.cpp) | 83 | Driver control: drive, intake and scoring buttons, piston toggles |

**Not mine:** the motion-control template underneath (PID, drive functions, odometry) was supplied by our coach. It is not copied here; it is credited file by file in the simulator repo's [ATTRIBUTION.md](https://github.com/Rogercy-whoop/vex-auton-visualizer/blob/main/ATTRIBUTION.md).

## Planning the 15 seconds

The notebook sets the order of priorities for autonomous (NB p.17):

> **complete the autonomous task > score autonomous points > set up an advantage for driver control**

- **The task** (the AWP conditions) needs both robots: at least 7 alliance blocks scored, blocks in three goals, 3 blocks taken out of a loader, neither robot touching the park zone. We aimed to complete as much of it as our robot could.
- **Points:** the preload, 3 field blocks and 3 loader blocks guarantee 7.
- **The advantage:** whoever holds the control zone at the end of autonomous starts driver control ahead, so the route should take it (NB p.18).

## Changing the routes after real matches

Two changes came from competition, not from planning (NB p.19–20):

- **Left side: long goal first.** Our first left route scored the middle goal first. In real matches the opponent was scoring the same middle goal at the same time and interfered. The second version scores the long goal first and reaches the middle goal *after* the opponent, so it still scores there and can also knock the opponent's blocks out.
- **Right side: drop the middle goal.** On the right the middle goal is the low one. Scoring it means reversing the intake to push blocks out of the front, which cost too much time and was hard to do. So all 7 blocks go into the long goal: field blocks → loader → score → take the control zone.

| Routine | What it is |
|---|---|
| `zuo` | Left side, first version |
| `superzuo` | Left side, revised: long goal first |
| `lanyou` | Right side: all seven blocks into the long goal |
| `superyou` | Right side, alternative route |
| `skillszuo` | Skills: four loader visits, each emptied into a long goal |
| `test` | Single moves for tuning |

## How the code grew, and was cut back

| Version | Date | `autons.cpp` | |
|---|---|---|---|
| Gen 2 | Aug 2025 | 262 lines | First routines for the ramp robot |
| Gen 3, "strongest version" | 5 Dec 2025 | 559 lines | Many experimental routes tried side by side |
| Gen 3, competition | 3 Feb 2026 | **392 lines** | Pruned to the six routines above |

## What I found later

All season, the drive moves were tuned by adjusting their timeouts. In 2024–25 our code let a drive end when it arrived within 1.5 in. In 2025–26 that settle band was set to 0. In July 2026 I read our coach's template line by line and found what that meant: the "arrived" test can never be true at 0, so **every drive move in 2025–26 ended on its timeout, never on arrival**. The timeout, not the distance, decided how far the robot went. I also found that the odometry had never been switched on.

That investigation led to the simulator I built next. → **[vex-auton-visualizer / FINDINGS.md](https://github.com/Rogercy-whoop/vex-auton-visualizer/blob/main/docs/FINDINGS.md)**
