<template>
    <ContentBase>
        <div class="row">
            <div class="col-3">
                <UserMess @follow="follow" @unfollow="unfollow" :user="user" />
                <br />
                <UserPost v-if="is_me" @post_a_post="post_a_post" />
            </div>
            <div class="col-9">
                <PostInfo
                    :user="user"
                    :posts="posts"
                    @delete_a_post="delete_a_post"
                />
            </div>
        </div>
    </ContentBase>
</template>

<script>
import UserMess from "@/components/UserMess.vue";
import ContentBase from "../components/ContentBase.vue";
import UserPost from "@/components/UserPost.vue";
import PostInfo from "@/components/PostInfo.vue";
import { computed, reactive } from "vue";
import { useRoute } from "vue-router";
import $ from 'jquery'
import { useStore } from "vuex";
export default {
    name: "UserProfileView",
    components: {
        ContentBase,
        UserMess,
        UserPost,
        PostInfo,
    },

    setup() {
        const store = useStore();
        const route = useRoute();
        const userId = parseInt(route.params.userId);
        const user = reactive({});
        const posts = reactive({});

        $.ajax({
            url: "https://app165.acapp.acwing.com.cn/myspace/getinfo/",
            type: "GET",
            data: {
                user_id: userId,
            },
            headers: {
                'Authorization': "Bearer " + store.state.user.access,
            },
            success(resp) {
                user.id = resp.id;
                user.username = resp.username;
                user.photo = resp.photo;
                user.followerCount = resp.followerCount;
                user.is_followed = resp.is_followed;
            },
        });

        $.ajax({
            url: "https://app165.acapp.acwing.com.cn/myspace/post/",
            type: "GET",
            data: {
                user_id: userId,
            },
            headers: {
                'Authorization': "Bearer " + store.state.user.access,
            },
            success(resp) {
                posts.count = resp.length;
                posts.posts = resp;
            },
        });

        const follow = () => {
            if (user.is_followed) return;
            user.is_followed = true;
            user.followerCount++;
        };

        const unfollow = () => {
            if (!user.is_followed) return;
            user.is_followed = false;
            user.followerCount--;
        };

        const post_a_post = (content) => {
            posts.count++;
            posts.posts.unshift({
                id: posts.count,
                userId: userId,
                content: content,
            });
        };

        const delete_a_post = (post_id) => {
            posts.posts = posts.posts.filter((post) => post.id !== post_id);
            posts.count = posts.posts.length;
        };

        const is_me = computed(() => userId === store.state.user.id);

        return {
            user,
            follow,
            unfollow,
            posts,
            post_a_post,
            delete_a_post,
            is_me,
        };
    },
};
</script>

<style scoped></style>
