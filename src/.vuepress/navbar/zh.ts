import { navbar } from "vuepress-theme-hope";

export const zhNavbar = navbar([
  "/",
  {
    text: "数据结构",
    icon: "structure",
    link: "/ds/"
  },
  {
    text: "计算机组成原理",
    icon: "computer",
    link: "/computer_organization/"
  },
  {
    text: "操作系统",
    icon: "linux",
    link: "/os/"
  },
  {
    text: "计算机网络",
    icon: "network",
    link: "/network/"
  }
]);
