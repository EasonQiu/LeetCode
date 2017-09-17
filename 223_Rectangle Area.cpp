class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C - A) * (D - B) + (G - E) * (H - F);
        if (C <= E || A >= G)  return area;
        if (B >= H || D <= F)  return area;
        return area - (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
    }
};