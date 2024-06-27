<template>
    <ContentBase>
        <div
            class="card"
            v-for="user in users"
            :key="user.id"
            @click="open_user_file(user.id)"
        >
            <div class="card-body">
                <div class="row">
                    <div class="col-2">
                        <img class="img-fluid" :src="user.photo" alt="" />
                    </div>
                    <div class="col-10">
                        <div class="username">{{ user.username }}</div>
                        <div class="fans">{{ user.followerCount }}</div>
                    </div>
                </div>
            </div>
        </div>
    </ContentBase>
</template>

<script>
import { ref } from "vue";
import ContentBase from "../components/ContentBase.vue";
import router from "@/router/index";
import { useStore } from "vuex";
import $ from "jquery";
export default {
    name: "UserlistView",
    components: {
        ContentBase,
    },

    setup() {
        const store = useStore();
        let users = ref([]);

        $.ajax({
            url: "https://app165.acapp.acwing.com.cn/myspace/userlist/",
            type: "get",
            success(resp) {
                users.value = resp;
            },
        });

        const open_user_file = (userId) => {
            if (store.state.user.is_login) {
                router.push({
                    name: "userprofile_index",
                    params: {
                        userId,
                    },
                });
            } else {
                router.push({
                    name: "login_index",
                });
            }
        };

        return {
            users,
            open_user_file,
        };
    },
};
</script>

<style scoped>
.img-fluid {
    width: 100px;
    height: 100px;
    border-radius: 30px;
}

.username {
    font-weight: bold;
}
.fans {
    font-size: 20px;
    color: aqua;
}

.card {
    margin-bottom: 10px;
}

.card:hover {
    box-shadow: 2px 2px 5px grey;
    transition: 500ms;
}

.col-10 {
    justify-content: center;
}
</style>
