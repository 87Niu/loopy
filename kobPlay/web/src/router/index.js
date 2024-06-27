import { createRouter, createWebHistory } from 'vue-router'
import NotFound from '../views/error/NotFound.vue'
import PkView from '../views/pk/PkView.vue'
import RanklistView from '../views/ranlist/RanklistView.vue'
import RecordView from '../views/record/RecordView.vue'
import UserBotView from '../views/user/bot/UserBotView.vue'
const routes = [
    {
        path: "/home/",
        name: "home",
        redirect: "/pk/",
    },
    {
        path: "/pk/",
        name: "pk_index",
        component: PkView,
    },
    {
        path: "/ranklist/",
        name: "ranklist_index",
        component: RanklistView,
    },
    {
        path: "/record/",
        name: "record_index",
        component: RecordView,
    },
    {
        path: "/user/bot/",
        name: "user_bot_index",
        component: UserBotView,
    },
    {
        path: "/404/",
        name: "404",
        component: NotFound,
    },
    {
        path: "/:catchAll(.*)",
        redirect: "/404/"
    },


]

const router = createRouter({
  history: createWebHistory(),
  routes
})

export default router
