# What being captain involved

I have been captain of team 117V since Grade 11 (2025–26, and now 2026–27). The team has six members, plus our mentor. The events below come from our records; the reflections are in my own words.

## The disputed match at Suzhou

The whistle went and we had won. Then their robot kept moving. Its control system had died sometime in the last few seconds and nobody had noticed, so it kept driving straight through the goals we'd spent months learning to score. Our coach wasn't allowed onto the field, so I walked up to the referees on my own while the other alliance stood beside me telling a different version. There was no video. I told them, slowly and twice, in my second language, that the match had ended at the whistle and that their robot had kept moving after it, through the goals. They ruled on what they'd seen from where they were standing and ordered a rematch.

Back in the pit, our driver was already saying my autonomous should have banked more points, and he was right. So I said it louder than he did: my auton was so bad they'd given us free practice. Someone laughed. We won the rematch.

We went on to win the Division 2 final, and in the overall final we won the first match and lost the next two. → [the official record](seasons/2025-26-push-back/README.md#suzhou-2123-november-2025)

## Learning from a win

In August 2025 our club's sister team, 117B, took a robot of our Gen 2 design to the WRCT 2025 selection and won the high-school division. While upgrading our own robot to Gen 2, I helped them during development, in the pits and with their code. Watching the design compete showed us three things it could not do: it leaked blocks at the middle goal, its autonomous gave no real advantage, and blocks jammed side by side.

Our improvement record marks two team meetings as the season's turning points. The first set out what was wrong with Gen 1. The second, after WRCT, decided to design a third robot instead of keeping the design that had just won (IR p.1, p.14–15). Three months later, Gen 3 won Division 2 in Suzhou. → [design log](seasons/2025-26-push-back/design-log.md#chapter-2-learning-from-a-win)

## Owning the code

Our notebook lists two programmers, 陈邢晔 and me. I wrote every autonomous routine myself, mostly because explaining my reasoning felt slower than just typing it. He was still learning, and mostly assisted me. What I learned is that a team where only one person understands the autonomous is a team with a single point of failure, and that person was me. Leading meant explaining why a route was ordered the way it was, not only shipping the code.

The routes changed after real matches: the left side was reordered to score the long goal first, and the right side dropped the middle goal entirely (NB p.19–20). By December the code had grown to 559 lines of experiments, and I cut it back to the six routines we actually used. → [code](seasons/2025-26-push-back/code/README.md)

## Writing things down, and building for the whole club

Our robots were documented as step-by-step build guides, written by our mentor, my teammates and me, and the team kept an engineering notebook, a season improvement record and a pre-match checklist. → [notebook and guides](seasons/2025-26-push-back/notebook/README.md)

After the season I built a simulator that runs a team's real autonomous code on a laptop, and designed it so that every team in our club could use it with their own robot. All four teams (117V, 11117V, 116X-323 and 3778W) now do. → [vex-auton-visualizer](https://github.com/Rogercy-whoop/vex-auton-visualizer)

## What I would do differently

I'd open the control template on day one and read it with the whole team. For two seasons we tuned how far the robot drove by feel, and only when I finally read the code line by line did I find that, all through 2025–26, every drive move had ended on its timer, never on arrival. Nobody was hiding that. We just never looked.

I'd also stop keeping the autonomous to myself. Writing every routine made me the bottleneck, and when one failed, everyone waited for me. Next time, the newest member would own one small routine from the first week, with me reviewing it, not rewriting it.

## What changed in me

In Grade 9 I sourced screws, assembled other people's designs and filmed matches from the stands. I was quiet and easy to hand things to. Later, once I was writing the code, when an autonomous run failed the blame found me quickly, because I wasn't going to argue back.

None of that was a rule. It was an arrangement, and it changed when I stopped waiting to be given things. I practised driving until I could justify asking for the second controller. As captain, I stood in front of referees alone in my second language. And at an away competition I noticed a Grade 10 boy by the barrier with a camera, waiting for a gap in the noise that was never going to come. I knew that look, because it had been mine. So I handed him a broken intake and walked away.
