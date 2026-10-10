# 2025–26 notebook and design documents

The originals are in Chinese and are kept complete and unedited. Each has an English summary below. To keep every file under 10 MB, the photos inside the PDFs were downscaled (longest side 1400 px) and re-saved as JPEG. Text, handwriting and drawings are untouched.

| File | What | Pages | Size | Written by |
|---|---|---|---|---|
| [2025-26-engineering-notebook.pdf](2025-26-engineering-notebook.pdf) | Engineering notebook (*工笔*), iPad handwriting | 20 | 9.4 MB (from 28.2) | The team |
| [2025-26-improvement-record.pdf](2025-26-improvement-record.pdf) | Season improvement record (*25-26赛季机器改进记录*), Gen 1 → Gen 2 → Gen 3 | 22 | 2.2 MB | Our mentor, my teammates and me |
| [2025-26-concept-study.pdf](2025-26-concept-study.pdf) | Concept study (*机型设计参考*) from the start of the season | 5 | 0.6 MB | Our mentor, my teammates and me |
| [build-guides/](build-guides/) | Step-by-step build guides for Gen 1 and Gen 2 | 2–25 each | 0.1–2.1 MB | Our mentor, my teammates and me |

## 1. Engineering notebook (*工笔*), summary

| Pages | Content |
|---|---|
| 1 | Cover: "117V Virtus PRO" with a line drawing of the robot |
| 2 | The six team members and their roles (see [ROLES.md](../../../ROLES.md)) |
| 3–7 | **Understanding the rules.** 88 blocks (preloads, match loads, field, loaders), goals and their capacities, scoring values, parking, the 5-second delayed scoring. **Motor budget:** total power ≤ 88 W, so the legal mixes of 11 W / 5.5 W motors are 8+0, 7+2, 6+4, 5+6, 0+16. The principle: use one motor for several jobs where possible, and don't add motors just to reach 88 W. Non-VEX parts (rope ≤ 6.35 mm, PVC sheet), the 18 in starting size, how WP/AWP/SP rankings work. The conclusion: *"autonomous matters most. Winning it eases the pressure on driver control and is the key to ranking."* |
| 8–9 | **Brainstorm.** Lift robot (simple, low centre of gravity, passes under the long goal; but unstable while scoring and drops stored blocks) vs "big stomach" robot (stores the most and is stable; but heavy and wide, and gets stuck turning between goals) vs **ramp robot** (agile, enough storage, front intake / rear scoring suits loader → long goal; but weaker grip and less pushing power). **Final choice: ramp robot.** It had no major weakness and balanced storage against agility. |
| 10–12 | **Problems → fixes:** long-goal alignment (a PVC plate plus an aluminium guide that self-centres the robot), middle-goal descoring, two-at-a-time jams (PVC funnel), blocks stopping on the loader plate (a zip tie) |
| 13–16 | **Robot design:** front intake / rear scoring; which roller turns which way for the high, middle and low goals; the first rubber-band rollers stored only 4 blocks; extra bands stiffened the top roller for the middle goal; band rollers → rubber wheels; chain moved inside and protected by a crossbeam |
| 17–20 | **Autonomous:** priorities (task > points > driver-control head start), the AWP task, left route v1 → v2 (long goal first), right route (drop the middle goal). See [code/README.md](../code/README.md#planning-the-15-seconds). |

**Third-party figures.** Pages 3–5 and 12 reproduce figures from the official VEX V5RC *Push Back* game manual, and pages 17–20 draw routes on a *Push Back* field image. They are used inside a student notebook to analyse the rules. They remain © VEX Robotics / REC Foundation and are not covered by this repository's licence. The official manual: [the REC Foundation knowledge base](https://v5rc-kb.recf.org/hc/en-us/articles/9652912628631-Game-Manual-and-Resources-for-VEX-V5-Robotics-Competition-Teams).

## 2. Season improvement record, summary

Gen 1 → Gen 2 → Gen 3 with SolidWorks renders and test photos. Summarised card by card in the [design log](../design-log.md).

## 3. Build guides

| File | Summary |
|---|---|
| [gen1-chassis.pdf](build-guides/gen1-chassis.pdf) (*V1.0 机器搭建*, 8 p) | Gen 1 chassis: **29 holes wide**, bearing and motor positions, wheel shaft stack-up |
| [gen1-intake.pdf](build-guides/gen1-intake.pdf) (*吸取搭建*, 16 p) | Gen 1 roller intake: 5.5 W + 11 W motors, shaft lengths (30.4 / 25.4 / 26.7 / 27.9 cm), sprocket and spacer order |
| [gen2-chassis.pdf](build-guides/gen2-chassis.pdf) (*v2.0 机器搭建*, 15 p) | Gen 2 chassis: **27 holes wide** between the 30-hole rails, 36T gears × 10, 3.25 in omni wheels × 4 |
| [gen2-intake.pdf](build-guides/gen2-intake.pdf) (*搭建intake*, 25 p) | Gen 2 intake: uprights, cut C-channels, PC plates, two sprocket stages, the "intake up" assembly, descore mount |
| [gen2-pneumatics.pdf](build-guides/gen2-pneumatics.pdf) (*气动装置搭建*, 7 p) | Side hook and loader pistons: drilling positions and lengths |
| [gen2-middle-goal-plate.pdf](build-guides/gen2-middle-goal-plate.pdf) (*中goal 板子制作*, 6 p) | Middle-goal PC plate: 90° bend at 30 mm, 30° bend at 15 mm, zip-tie holes |
| [gen2-sled.pdf](build-guides/gen2-sled.pdf) (*Sled 安装*, 2 p) | Sled mounting |

*简单底盘搭建* ("simple chassis") is the first half of *v2.0 机器搭建*, so it is not repeated.

## Not included

- *2025-2026 规则解读* (rules interpretation): a teaching handout made mostly of game-manual images, with nothing of ours to add. The official manual is linked above.
