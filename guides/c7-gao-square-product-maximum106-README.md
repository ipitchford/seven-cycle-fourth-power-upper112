# Exact maximum 106 for Gao square-product gadgets

The largest code produced by Gao’s Lemma 4 from **two gadgets in C₇ ⊠ C₇ is exactly 106**. The two gadgets may differ, and their independent seeds need not be maximum. The archive includes a 106-word construction and the complete exact exclusion needed for this method-specific optimum.

This does not determine α(C₇⁴). The broader research currently has local proof evidence for **108 ≤ α(C₇⁴) ≤ 112**; delivery and replay of that broader proof are separate. In particular, this 106-word construction does not improve the known unrestricted lower bound. Other factor splits and recursive constructions are outside this theorem.

The unchanged archive passed a fresh clean-extraction replay in **14.63 seconds** on one CPU, followed by two independent byte and receipt readbacks. It regenerates the catalogues, checks all 924 auxiliary-eight classes and their 866 six-cliques, excludes five-cliques for all three auxiliary-ten classes, verifies maximum-seed cases and the exact scalar bound, and checks all 5,565 pairs of the 106-word witness. No historical result receipt is used as a mathematical shortcut.

## Replay

Requirements: Python 3.10+, a C++17 compiler available as `c++`, and Linux or macOS. Only the Python standard library is required; no network or installation is needed. Extract the ZIP, enter `gao-square-method106`, then run:

```sh
python3 -B -O replay.py --work-dir /absolute/path/to/new-scratch
```

The scratch directory must be new and outside the extracted package. Omitting `--work-dir` creates a fresh temporary directory. The replay runs serially with a 120-second overall limit; an incomplete run does not verify the theorem. Success is reported as `PASS_FRESH_EXACT_GAO_SQUARE_PRODUCT_MAXIMUM_106`.

The archive contains the proof, source, complete square catalogues, gadget, original-coordinate witness, and a manifest. The separately supplied proof and replay/readback receipts make the result inspectable without unpacking it. The delivery receipt binds the exact delivered files.

Archive SHA-256:

```text
69f65079d470991d6281276e4757cf55a844a8b7551a28dc20f87bd6f75d129b
```

Archive size: 1,030,149 bytes; 20 members, approximately 3.5 MB uncompressed.

Primary construction: Yu Gao, *A Recursive Construction Improving the Lower Bound on the Shannon Capacity of C₇*, [arXiv:2607.27869v1](https://arxiv.org/html/2607.27869v1), Definition 3 and Lemma 4. This is a research evidence package, not a publication or a novelty claim.
