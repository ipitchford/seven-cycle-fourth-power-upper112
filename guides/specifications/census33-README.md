# Exact census of maximum codes in the third strong power of the seven-cycle

The complete census contains **16,672,544 labeled independent sets of size 33
in C7³**, forming **1,016 classes** under coordinate permutations, reflections,
and translations. This is an auxiliary finite classification. The requested
fourth-power problem remains unresolved: **108 ≤ α(C7⁴) ≤ 115**.

No novelty or external peer-review claim is made. This is a local research
package prepared for assessment, not a published Evidence Press release.

## What is counted

A code is a subset of the 343 triples in {0,…,6}³. Two selected triples must
differ by 2, 3, 4, or 5 modulo 7 in at least one coordinate. The separately
replayed upper bound 33 makes every code counted here maximum.

The symmetry group has order 16,464. Its orbit distribution is:

| Number of labeled codes in an orbit | Number of orbits |
|---:|---:|
| 16,464 | 1,011 |
| 8,232 | 1 |
| 5,488 | 3 |
| 2,744 | 1 |

The binary archive holds **4,560 normalized configurations**, enough to
represent every class. It does not hold all 16,672,544 labeled configurations.
Normalization fixes a coordinate profile and one maximum two-dimensional
section; it does not require any symmetry of the whole code.

## Why the enumeration is complete

Write a₀,…,a₆ for the sizes of the seven layers in one coordinate. Every
adjacent pair projects injectively to an independent set in C7², so
aᵢ+aᵢ₊₁ ≤ 10. The seven deficits qᵢ=10−aᵢ−aᵢ₊₁ sum to four.
There are exactly 20 deficit patterns up to rotation and reflection. Their
canonical representatives start with zero, making the initial two-layer
union one of the three symmetry classes of maximum square codes.

For each pattern, the program tries every split of each of those three
representatives. It then enumerates every compatible layer of the required
size and checks closure around the seven-cycle. The archive retains every
successful configuration. Two different orbit algorithms recover the same
1,016 classes and total count. The detailed coverage argument and source
review are in [the independent audit](assurance/independent-audit.md).

## Fresh reproduction

Requirements: Python 3.10 or later, a C++17 compiler, and no third-party Python
packages. From this directory run:

```sh
python3 -O verification/replay.py --work-dir /tmp/c7-census-fresh --receipt /tmp/c7-census-receipt.json
```

Use new paths: existing work directories or receipt files are rejected. The
replay checks the file manifest, independently reconstructs all 980 maximum
square codes, replays the three-dimensional upper bound, checks every archived
word pair, reruns the entire configuration search, and runs both orbit
algorithms. It compares the fresh archive byte for byte and compares every
search-node count with the retained run. Corrupted inputs and incomplete
completion receipts are tested as negative controls. The search took about
109 seconds on the discovery machine; slower hardware may need a larger
`--per-profile-seconds` value. A partial run is a failed verification.

The retained archive SHA256 is
`74d12747b1f5940ff4c10c5a6a7c98149f092f9c8ccf9dbc4d89a59624f4e929`.

## Data format and assurance limits

`data/census33.bin` begins with the eight ASCII bytes `C7CENS33`. Each following
57-byte record contains a one-byte profile index and seven unsigned 64-bit
little-endian layer masks. A bit at position 7b+c represents the triple
(a,b,c) in layer a. Only the bottom 49 bits may be set. Integer word IDs in
`data/orbits33.json` use 49a+7b+c.

The independent audit used a separate representation, canonical ordering,
and orbit-stabilizer calculation. It reviewed the exhaustive search but did
not implement a second exhaustive configuration search. The package is an
exact finite computation, not a proof-assistant formalization. Correctness
still relies on the stated mathematical reduction, inspected source,
compiler, and runtime. The fresh replay guards against stale or incomplete
retained results. Fourth-power solver timeouts are not evidence of optimality.

Creator: Anonymous. Original prose and generated data: CC0 1.0. Original
source code: MIT. AI assistance: the computation, documentation, and internal
audit were produced with Codex; the internal audit is not external peer review.
