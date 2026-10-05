class Solution {

    public String encode(List<String> strs) {
        StringBuilder sb = new StringBuilder();
        StringBuilder sb2 = new StringBuilder();
        for (String str: strs) {
            sb.append(str).append("#");
            sb2.append(str).append("^");
        }
        return sb.append(sb2).toString();
    }

    public List<String> decode(String str) {
        List<String> strlist = new ArrayList<>();
        int l = str.length() / 2;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < l; i++) {
            if (str.charAt(i) == '#' && str.charAt(i + l) == '^') {
                strlist.add(sb.toString());
                sb.setLength(0);
                continue;
            }
            sb.append(str.charAt(i));
        }
        return strlist;
    }
}
