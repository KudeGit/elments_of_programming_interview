#include <iostream>
#include <vector>
#include <unordered_set>
#include "utils.hpp"
#include <cassert>

using namespace std;

int find_duplicate (const std::vector<int>& A)
{
    debug(A.size());
    const int N = std::sqrt(A.size());
    debug(N);
    std::vector<int> K(N, 0);
    for (const auto& a: A) {
        auto x = std::min((a-1)/N, static_cast<int>(K.size() - 1));
        ++K[x];
    }
    debug(K);
    auto range = 0;
    for (int i = 0; i < K.size(); ++i) {
        if(K[i] > N) {
            range = i;
            break;
        }
    }
    unordered_set<int> is_present;
    for (const auto& a: A) {
        auto x = std::min((a-1)/N, static_cast<int>(K.size() - 1));
        if (x >= range && x < (range+1)) {
            if (is_present.find(a) != is_present.end()) {
                return a;
            }
            is_present.insert(a);
        } 
    }

    return -1;
}

int main (void)
{
    std::vector<int> A = {442, 249, 406, 112, 202, 98, 228, 99, 38, 10, 402, 505, 104, 340, 265, 317, 190, 403, 148, 276, 145, 199, 456, 489, 237, 226, 470, 342, 405, 339, 142, 234, 542, 96, 71, 297, 261, 262, 130, 119, 428, 82, 432, 219, 430, 439, 188, 397, 227, 478, 400, 111, 451, 388, 34, 303, 158, 68, 74, 502, 36, 80, 243, 508, 73, 324, 103, 325, 46, 211, 133, 144, 480, 404, 231, 416, 401, 370, 3, 48, 407, 195, 212, 300, 47, 409, 44, 21, 248, 105, 56, 319, 117, 149, 334, 455, 544, 429, 464, 143, 75, 197, 316, 292, 352, 282, 525, 194, 87, 242, 283, 333, 356, 440, 338, 100, 366, 368, 520, 129, 479, 499, 408, 496, 307, 173, 347, 101, 293, 523, 114, 5, 393, 178, 329, 394, 302, 59, 492, 175, 537, 538, 454, 217, 84, 344, 126, 360, 471, 433, 238, 465, 62, 165, 43, 139, 530, 512, 280, 312, 518, 385, 8, 29, 93, 467, 320, 64, 120, 452, 391, 358, 522, 445, 274, 240, 172, 449, 205, 18, 328, 453, 278, 536, 69, 331, 166, 92, 50, 462, 501, 27, 106, 72, 30, 11, 289, 318, 343, 245, 497, 411, 218, 363, 151, 85, 37, 337, 285, 511, 137, 426, 155, 254, 376, 136, 235, 90, 418, 60, 487, 181, 232, 486, 287, 515, 362, 86, 395, 255, 159, 527, 336, 378, 375, 115, 15, 179, 33, 67, 177, 247, 51, 424, 284, 357, 157, 162, 253, 135, 216, 122, 41, 118, 359, 209, 355, 373, 437, 23, 214, 97, 191, 447, 83, 267, 256, 20, 52, 236, 39, 259, 204, 353, 510, 55, 203, 305, 290, 206, 413, 488, 14, 380, 174, 540, 299, 463, 485, 371, 309, 186, 481, 192, 200, 156, 288, 534, 475, 382, 184, 152, 220, 189, 521, 443, 110, 160, 369, 171, 183, 468, 65, 108, 427, 423, 516, 146, 384, 138, 222, 35, 365, 163, 458, 132, 498, 372, 66, 345, 326, 396, 40, 141, 22, 491, 19, 286, 415, 434, 121, 1, 270, 313, 78, 446, 379, 392, 31, 9, 180, 420, 45, 76, 26, 460, 49, 89, 279, 54, 57, 208, 519, 241, 275, 386, 441, 533, 296, 507, 422, 109, 196, 361, 2, 4, 474, 182, 53, 310, 414, 291, 364, 61, 535, 398, 134, 24, 509, 335, 484, 263, 476, 154, 304, 25, 306, 444, 32, 266, 210, 539, 473, 322, 7, 466, 529, 436, 350, 494, 16, 161, 116, 459, 168, 301, 215, 213, 91, 438, 102, 224, 277, 13, 17, 28, 258, 70, 531, 541, 532, 315, 187, 381, 170, 272, 147, 223, 252, 421, 81, 271, 201, 164, 176, 58, 257, 321, 95, 377, 472, 113, 94, 457, 153, 469, 225, 140, 399, 281, 308, 230, 193, 390, 514, 483, 412, 327, 12, 543, 367, 493, 504, 419, 524, 198, 77, 295, 417, 389, 374, 435, 42, 330, 528, 311, 490, 387, 341, 517, 127, 298, 169, 185, 125, 233, 410, 477, 128, 239, 107, 448, 354, 221, 425, 264, 294, 323, 88, 526, 124, 351, 349, 506, 150, 348, 246, 482, 260, 251, 167, 503, 250, 268, 273, 207, 540, 332, 63, 431, 131, 383, 6, 495, 244, 346, 269, 79, 450, 513, 123, 461, 314, 229, 500};
    auto res = find_duplicate(A);
    debug(res);
    return 0;


Meenakshi
 CSCva17430


Beni v152_3_e_throttle) 
cauvery (v152_4_e_throttle) 	
mainline (danueb) (dsgs_pi6) 

152-2.E3

cauvery
Beni
Amur	





Enterprise Fabric Enabling UCI (Architecture Commit)

}





mkdir /nobackup/dcuda/msp_dsgs_pi6-2016-07-05
cd /nobackup/dcuda/msp_dsgs_pi6-2016-07-05
source /nfs/nova/tools/latest/bin/set_novaenv;
acme nw -proj v3_9_e_nova_throttle -sb binos
Scanning the source base and preparing the workspace, please wait ...
...

mkdir ngwc
cd /nobackup/dcuda/msp_dsgs_pi6-2016-07-05/ngwc
acme pull -dl main -sb ngwc
Scanning the source base and preparing the workspace, please wait ...

cd /nobackup/dcuda/msp_dsgs_pi6-2016-07-05/wafroot
wab init -w ngwc,../ngwc


cd /nobackup/dcuda/msp_dsgs_pi6-2016-07-05/
mkdir wcm
cd /nobackup/dcuda/msp_dsgs_pi6-2016-07-05/wcm
acme pull -dl v3_9_e_wcm_throttle -sb gate
Scanning the source base and preparing the workspace, please wait ...



cd /nobackup/dcuda/msp_dsgs_pi6-2016-07-05/wafroot
wab init -w wcm,../wcm
mbs configure

, v152_5_e_throttle, , 

v3_9_e_nova_throttle v3_9_e_ngwc_throttle v3_9_e_wcm_throttle


