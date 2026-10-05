# Fourth strong power of the seven-cycle: certificate for the bounds 108 to 112

The verified result is

\[
108\leq\alpha(C_7^{\boxtimes4})\leq112.
\]

The exact value and the existence of a 109-word independent set remain
unresolved. This therefore does not completely solve Problem 2 in the supplied
list. The archive certifies the improved upper bound and includes a literal
108-word lower witness.

The graph has the 2,401 words in `{0,1,…,6}^4` as vertices. Two distinct words
are adjacent when their differences in every coordinate are 0, 1 or −1 modulo
7. The lower witness has 108 distinct words, with all 5,778 pairs checked
directly in this graph.

## What was verified

The archive preserves two complete certificate components. Component N
excludes the case with two nonadjacent maximum 33-point bands. Its fresh replay
also checks the complete three-dimensional maximum-code census, the proof that
34 three-dimensional words are impossible, and the mixed-cycle upper bound of
77. Component A excludes the remaining adjacent-band case. The mathematical
derivation explains why these cases cover every hypothetical 113-word code.

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
