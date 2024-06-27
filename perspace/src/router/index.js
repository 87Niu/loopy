import { createRouter, createWebHistory } from 'vue-router'
import HomeView from '@/views/HomeView.vue'
import LoginView from '@/views/LoginView.vue'
import RegisterView from '@/views/RegisterView.vue'
import NotFoundView from '@/views/NotFound.vue'
import UserlistView from '@/views/UserlistView.vue'
import UserProfileView from '@/views/UserProfileView.vue'
const routes = [
    {
        path: "/home",
        name: "home_index",
        component: HomeView
    },
    {
        path: "/login/",
        name: "login_index",
        component: LoginView
    },
    {
        path: "/register/",
        name: "register_index",
        component: RegisterView
    },
    {
        path: "/userlist/",
        name: "userlist_index",
        component: UserlistView
    },
    {
        path: "/userprofile/:userId/",
        name: "userprofile_index",
        component: UserProfileView
    },
    {
        path: "/404/",
        name: "404",
        component: NotFoundView
    },
    {
        path: "/:catchAll(.*)",
        redirect: "/404/"
    }
]

const router = createRouter({
  history: createWebHistory(),
  routes
})

export default router
