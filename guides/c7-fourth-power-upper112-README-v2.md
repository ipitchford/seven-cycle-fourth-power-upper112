# Fourth strong power of the seven-cycle: certificate for the bounds 108 to 112

The verified result is

\[
108\leq\alpha(C_7^{\boxtimes4})\leq112.
\]

The exact value and the existence of a 109-word independent set remain
unresolved. The archive certifies the upper bound and includes a literal
108-word lower witness.

For historical comparison, Table 1 of Polak and Schrijver, *New lower bound on
the Shannon capacity of C7 from circular graphs*, Information Processing
Letters 143 (2019), 37–40, records the fourth-power bounds 108–115. Its upper
bound uses an earlier recursive inequality of Baumert et al. The present
certificate lowers that recorded upper bound to 112. This comparison does not
by itself establish priority against all subsequent work.
[Paper and Table 1](https://arxiv.org/html/1808.07438v2);
[journal DOI](https://doi.org/10.1016/j.ipl.2018.11.006).

The graph has the 2,401 words in `{0,1,…,6}^4` as vertices. Two distinct words
are adjacent when their differences in every coordinate are 0, 1 or −1 modulo
7. The lower witness has 108 distinct words, with all 5,778 pairs checked
directly in this graph.

## What was verified

Fix one coordinate. A **layer** contains words with one prescribed value of
that coordinate. A **band** is the union of two cyclically adjacent layers.
Deleting the fixed coordinate projects each band injectively to an independent
set in the cubic graph \(H=C_7^{\boxtimes3}\), whose maximum size is 33.

In a hypothetical 113-word set, the seven band sizes sum to 226, because each
word lies in two bands. If at most one band had size 33, that sum would be at
most \(33+6\cdot32=225\). Thus there are at least two 33-point bands. Two bands
either share a layer or are disjoint. Component N excludes any pair of disjoint
33-point bands. The only remaining layer profile, up to cyclic translation, is
\((16,17,16,16,16,16,16)\), with the two 33-point bands sharing the 17-point
layer; component A excludes it. These are exhaustive cases for size 113.

The archive preserves two complete certificate components. Component N
excludes the case with two nonadjacent maximum 33-point bands. Its fresh replay
also checks the complete three-dimensional maximum-code census, the proof that
34 three-dimensional words are impossible, and
\(\alpha(C_5\boxtimes C_7^{\boxtimes3})\leq77\). This is the **mixed-cycle bound**:
the first factor is a five-cycle, including its closing edge. Five consecutive
layers outside a fixed band instead form a five-vertex path, so one cannot
deduce a bound of 110 by adding 33 and 77. In component A, the bound is applied
to an actual five-cycle produced by an intersection-and-collapse construction;
the mathematical derivation gives its details.

A **catalogue class** is an orbit of 33-point independent subsets of the cubic
graph under permutations of its three coordinates and independent cyclic
translations and reflections in each coordinate. The complete catalogue has
1,016 classes. **Normalization** means applying these graph symmetries (and
the stated symmetries of the outer cycle) to choose a representative while
retaining every case needed by the proof.

Both full mathematical component replays completed successfully before
packaging. The reference run took 3,632 seconds for A and 3,595 seconds for N:
about one hour per component. All 1,016 catalogue classes were covered. The
completed fresh receipts and actual process-exit records are retained inside
the component archives.

The subsequent packaging check preserved the exact component bytes. An
independent combined readback checked all 17 outer archive members, the fresh
extraction, both nested archive identities, all 462 possible layer-size profiles
and all 5,778 lower-witness pairs. ZIP wrapping did not trigger another full
mathematical replay. The delivery records distinguish the completed fresh
proof replays from these later byte-conservation and composition checks.

## Run a new full replay

From the directory containing the ZIP:

```sh
unzip c7-fourth-power-upper112.zip
cd c7-fourth-power-upper112
python3 -B verify.py --bundle . --out ../NEW_MAIN112_REPLAY
```

Choose a new output directory outside the extracted bundle. This command runs
N and its prerequisites afresh, then A, and checks the lower witness and the
normalization. A completed new run writes `PASS_FRESH_MAIN112_BOUND` in
`NEW_MAIN112_REPLAY/result.json`. A failed, partial, timed-out or UNKNOWN run
does not receive that status.

Requirements are Python 3.10 or later and a GCC/Clang C++17 compiler supporting
`unsigned __int128`, on macOS or Linux. The A checker uses system CommonCrypto
on macOS, or OpenSSL's crypto library and development headers on Linux. No SAT
or numerical optimization solver installation is needed to replay the retained
certificates. Runs are sequential with one computational thread and a
three-hour limit per component. Reference memory use stayed below 1.3 GiB.
Keep at least 20 GiB free throughout the run, with additional space for
extraction and replay outputs.

## Delivered files

This revision is an explanatory guide dated 2026-10-05. It leaves the sealed
archive and all original delivery files unchanged. The original delivery
receipt binds the original `c7-fourth-power-upper112-README.md`, not this v2
guide. No new full component replay is claimed for this documentation revision.

- `c7-fourth-power-upper112.zip`: the self-contained source, data, proof and
  fresh-replay evidence bundle, including both unchanged component archives.
- `c7-fourth-power-upper112-proof.md`: the mathematical derivation, copied
  unchanged from the checked archive.
- `c7-fourth-power-upper112-composition.json`: the binding between the completed
  component replays and the fourth-power bound.
- `c7-fourth-power-upper112-archive-receipt.json`: assembly and exact extraction
  results.
- `c7-fourth-power-upper112-independent-readback.json`: independent combined
  archive, normalization and literal-witness checks.
- `c7-fourth-power-upper112-delivery-receipt.json`: hashes and byte counts for
  the delivered files, checked again after copying.

The ZIP is 786,289,587 bytes. Its SHA-256 is:

```text
a9a54be2206c5e3fdf9059f687b593fb4ccb7506676edc36ce732ec2109ca347
```

The draft author is Anonymous. The scoped MIT/CC0 terms for newly original
material, and all retained notices for nested or inherited material, are
described inside the archive. The certificate does not itself establish
novelty, external peer-review acceptance or publication status.
