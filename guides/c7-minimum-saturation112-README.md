# Minimum-saturation exclusion at size 112

Fresh portable replay passed on 5 October 2026. The unchanged archive excludes a balanced 112-point independent code in the fourth strong power of the seven-cycle when it has no size-33 cubic band and all six coordinate pairs attain the minimum saturation count.

The complete candidate sequence is **11,175 → 43 → 0**. This does not exclude all 112-point codes, establish an upper bound of 111, or decide whether 109 exists.

Unzip `c7-minimum-saturation112.zip`, then run from its `c7-minimum-saturation112` directory:

```sh
python3 -B -O verify.py --work-dir /absolute/path/to/new-scratch --census-seconds 1200 --verification-seconds 1800
```

Use a new scratch directory outside the extracted package. Requirements are Python 3.10 or later and a compatible C++17 compiler on macOS or Linux. No solver library, network service or original workspace is needed. This command freshly regenerates the complete restricted cubic census, both trace dictionaries and every necessary-allocation problem, then checks all complete proof trees and the 43 intermediate partial allocations.

The observed full replay finished successfully in 1,164.78 seconds, with a measured peak resident set of 140,591,104 bytes. It checked 40,133,217 proof bytes: 10,002,573 binary branches and 10,013,748 leaves across 11,175 complete exclusion trees. All intermediate SAT records were retained until excluded by the next round. No unresolved cases remain within this conditional theorem.

The separate delivery receipt binds the exact ZIP and fresh replay. A second readback checked every archived file, every completed per-case record, all consumed proof hashes and the full stage partitions. Internal README wording describes the package's frozen pre-replay preparation state; this dated delivery note and the attached actual replay receipt record its subsequent successful verification. The sealed archive itself was not modified.

These are local research materials. Historical novelty, external peer review and publication remain separate questions.
