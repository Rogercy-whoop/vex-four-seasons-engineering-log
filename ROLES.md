# Who did what

Our 2025–26 engineering notebook (NB p.2) lists the team's six members with one label each:

| Member | Label in the notebook | English |
|---|---|---|
| 徐子凡 (Xu Zifan) | 操作 | Driver |
| **陈誉 (Chen Yu, me)** | **程序** | **Programming** |
| 陈邢晔 (Chen Xingye) | 程序 | Programming |
| 潘逸曦 (Pan Yixi) | 设计 | Design |
| 兰济成 (Lan Jicheng) | 设计 | Design |
| 戴钰轩 (Dai Yuxuan) | 搭建 | Build |

These were primary labels, not boundaries; on a six-person team building three robots in one season, roles overlapped. My label says *programming*, but I was also the captain, built the CAD with our mentor, and co-wrote the team's documents. This page sets out what I did each season, with the file that shows it.

## 2025–26 *Push Back* (Grade 11), team 117V: captain, lead programmer

| What | My part | Evidence |
|---|---|---|
| Autonomous routines | Wrote all of them: `zuo`, `superzuo`, `lanyou`, `superyou`, `skillszuo`, `test` | [`code/autons.cpp`](seasons/2025-26-push-back/code/autons.cpp), 392 lines |
| Mechanism helpers and driver control | Wrote them | [`autofunction.cpp`](seasons/2025-26-push-back/code/autofunction.cpp), [`user.cpp`](seasons/2025-26-push-back/code/user.cpp) |
| PID tuning | Tuned the gains and timeouts on the robot | `autons.cpp`, `default_constants()` |
| SolidWorks CAD | Built the models with our mentor, including the Gen 3 robot (`V2-RG`) and custom parts such as the centring plate | [`cad/`](seasons/2025-26-push-back/cad/README.md) |
| Engineering notebook and design documents | Co-wrote with my teammates and our mentor | [`notebook/`](seasons/2025-26-push-back/notebook/README.md) |
| Captaincy | | [leadership.md](leadership.md) |
| Help for our sister team 117B | Development, pit and code help when they won the WRCT 2025 selection | [design log](seasons/2025-26-push-back/design-log.md#chapter-2-learning-from-a-win) |

**My teammates:** 徐子凡 was our driver. 潘逸曦 and 兰济成 worked on design, and 戴钰轩 on building. 陈邢晔 was learning to program and assisted me.

**Our mentor**, the school's robotics teacher, built the SolidWorks models with me, and co-wrote the design documents and build guides.

**Not ours:**
- The motion-control template (`PID.cpp`, `drive.cpp`, `odom.cpp`, `util.cpp`) is our coach's. It is credited in the simulator repo's [ATTRIBUTION.md](https://github.com/Rogercy-whoop/vex-auton-visualizer/blob/main/ATTRIBUTION.md) and not copied here.
- The Gen 3 idea of piston-lifted double parking with a single storage channel came from watching team **16610A** ([design log](seasons/2025-26-push-back/design-log.md#chapter-2-learning-from-a-win)).

## 2024–25 *High Stakes* (Grade 10), team 117C: programmer → lead programmer

| What | Evidence |
|---|---|
| The team's code: project "117c", March → May 2025, `autons.cpp` 699 → 908 lines, plus a proportional controller for the lift arm | [2024–25 code](seasons/2024-25-high-stakes/README.md#code) |
| SolidWorks model of the "V2.0" robot, with our mentor | [screenshot](seasons/2024-25-high-stakes/media/v2.0-cad-edrawings.jpg) |
| Build guides, co-written with our mentor and teammates | [build-guides/](seasons/2024-25-high-stakes/build-guides/) |

## 2023–24 *Over Under* (Grade 9), team 117C: new member

Sourcing parts, scouting and filming matches, while the club's robot went through four versions ([build guides](seasons/2023-24-over-under/README.md)).

## 2026–27 *Override* (Grade 12), team 117V: captain

In progress.
