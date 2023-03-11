import { defineUserConfig } from "vuepress";
import theme from "./theme.js";

export default defineUserConfig({
  base: "/",

  locales: {
    "/": {
      lang: "zh-CN",
      title: "Yunwu Notebook",
      description: "某不知名408考研生的笔记本",
    }
  },

  theme,

  // Enable it with pwa
  // shouldPrefetch: false,
});
